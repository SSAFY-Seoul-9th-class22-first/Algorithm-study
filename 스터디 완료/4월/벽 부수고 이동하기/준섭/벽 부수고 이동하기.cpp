#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct node {
	int y, x;
	int brokenWall;
};

int n, m;
int arr[1010][1010];
int visited[1010][1010][2];
int d[2][4] = {
	-1, 0, 1, 0,
	0, 1, 0, -1
};
int ans;
void init();

void bfs() {

	queue<node> q;
	q.push({ 1, 1, 0 });
	visited[1][1][0] = 1;

	while (!q.empty()) {
		node now = q.front();
		q.pop();
		// 도착했을 경우
		if (now.y == n && now.x == m) {
			ans = visited[now.y][now.x][now.brokenWall];
			return;
		}
		for (int dir = 0; dir < 4; dir++) {
			node next = { now.y + d[0][dir], now.x + d[1][dir], now.brokenWall };

			// 배열 범위 밖으로 나갈 경우
			if (next.y == 0 || next.x == 0 || next.y > n || next.x > m) continue;

			// 벽을 만났는데 벽을 부수고 온 경우 => 벽을 한번 부쉈기에 더 부숴서 진행할 수가 없다!
			if (arr[next.y][next.x] == 1 && now.brokenWall == 1) continue;

			// 벽을 처음만났다면
			if (arr[next.y][next.x] == 1) next.brokenWall++;

			// 벽을 만나서 왔다면 [][][1]일 꺼고 아니라면 [][][0]
			if (visited[next.y][next.x][next.brokenWall] != 0) continue;

			visited[next.y][next.x][next.brokenWall] += visited[now.y][now.x][now.brokenWall] + 1;

			q.push(next);
		}
	}

}

int main() {

	init();
	bfs();
	if (ans == 0) cout << -1;
	else cout << ans;
	return 0;
}

void init() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			arr[i][j + 1] = str[j] - '0';
		}
	}
} 