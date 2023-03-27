#include <iostream>
#include <queue>

using namespace std;

struct node {
	int y, x;
};

struct p {
	int num, gas;
};

struct arrStruct {
	int num, y, x;
};

struct pqs {
	int y, x, dis;
	bool operator < (pqs right) const {
		if (dis > right.dis) return true;
		if (dis < right.dis) return false;
		if (y > right.y) return true;
		if (y < right.y) return false;
		if (x > right.x) return true;
		if (x < right.x) return false;
		return false;
	}
};

int n, m, gas;
arrStruct startArr[22][22];
int endArr[22][22];
int d[2][4] = {
	-1, 0, 1, 0,
	0, 1, 0, -1
};
int flag;
node taxi;

p bfs(int y, int x) {
	queue<node> q;
	priority_queue<pqs> pq;
	p returnP = { 0, 0 };
	q.push({ y, x });
	int visited[22][22] = { 0, };
	visited[y][x] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int dy = now.y + d[0][dir];
			int dx = now.x + d[1][dir];
			if (dy < 0 or dx < 0 or dy == n or dx == n) continue;
			if (visited[dy][dx] != 0) continue;
			if (startArr[dy][dx].num == -1) continue;
			visited[dy][dx] = visited[now.y][now.x] + 1;
			if (startArr[dy][dx].num > 0)
				pq.push({ dy, dx, visited[dy][dx] });
			q.push({ dy, dx });
			if (pq.size() == m + 1) {
				pqs save = pq.top();
				returnP = { startArr[save.y][save.x].num, visited[save.y][save.x] - 1 };
				taxi.y = save.y;
				taxi.x = save.x;
				startArr[save.y][save.x].num = 0;
				return returnP;

			}
		}
	}
	flag = 1;
	return returnP;
}

int bfs2(int y, int x, arrStruct man) {
	queue<node> q;
	q.push({ y, x });
	int visited[22][22] = { 0 };
	visited[y][x] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int dy = now.y + d[0][dir];
			int dx = now.x + d[1][dir];
			if (dy < 0 or dx < 0 or dy == n or dx == n) continue;
			if (visited[dy][dx] != 0) continue;
			if (endArr[dy][dx] == -1) continue;
			if (man.y == dy and man.x == dx) {
				taxi.y = dy;
				taxi.x = dx;
				return visited[now.y][now.x];
			}
			visited[dy][dx] = visited[now.y][now.x] + 1;
			q.push({ dy, dx });
		}
	}
	flag = 1;
	return 0;
}

int main() {

	// M명의 승객을 태워야함(빈칸에 서있음)
	// N by N 격자
	// 최단경로
	// 승객을 고를때는 가장 거리가 짧은 승객을 선택
	// 만약에 행 작게 또 만약에 열 작게
	// 

	cin >> n >> m >> gas;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		cin >> startArr[i][j].num;
		if (startArr[i][j].num == 1) startArr[i][j].num = -1;
		endArr[i][j] = startArr[i][j].num;
	}


	cin >> taxi.y >> taxi.x;
	taxi.y--; taxi.x--;
	for (int i = 1; i <= m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		startArr[a - 1][b - 1].num = i;
		startArr[a - 1][b - 1].y = c - 1;
		startArr[a - 1][b - 1].x = d - 1;
		endArr[c - 1][d - 1] = i;
	}

	while (m--) {

		// 택시가 있는 위치에서 가장 가까운 승객을 먼저 찾는다.
		int man;
		if (startArr[taxi.y][taxi.x].num > 0) {
			man = startArr[taxi.y][taxi.x].num;
			startArr[taxi.y][taxi.x].num = 0;
		}
		else {
			// 최단 경로에 있는 man을 찾아줘야함
			p p1 = bfs(taxi.y, taxi.x);
			if (flag) {
				cout << -1;
				return 0;
			}
			man = p1.num;
			gas -= p1.gas;
		}
		if (gas <= 0) {

			cout << -1;
			return 0;
		}
		int bfsDis = bfs2(taxi.y, taxi.x, startArr[taxi.y][taxi.x]);
		if (flag) {
			cout << -1;
			return 0;
		}
		gas -= bfsDis;
		if (gas < 0) {
			cout << -1;
			return 0;
		}
		else gas += bfsDis * 2;

	}

	cout << gas;

	return 0;
}