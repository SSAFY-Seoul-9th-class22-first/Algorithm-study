#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int y, x;
};

int arr[51][51];
int n, m;
vector<node> virusV;
vector<node> path;
int visited[51][51];
int d[2][4] = {
	-1, 0, 1, 0,
	0, 1, 0, -1
};
int MIN = 987654321;

void bfs(queue<node> nowQ) {

	while (!nowQ.empty()) {

		node now = nowQ.front();
		nowQ.pop();

		for (int dir = 0; dir < 4; dir++) {

			int dy = now.y + d[0][dir];
			int dx = now.x + d[1][dir];

			if (dy < 0 or dx < 0 or dy == n or dx == n) continue;

			// 벽이 아니고 아직 방문하지 않은 곳이라면
			if (arr[dy][dx] != 1 and visited[dy][dx] == -1) {
				visited[dy][dx] = visited[now.y][now.x] + 1;
				nowQ.push({ dy, dx });
			}
		}
	}

	// 핵심은 비활성 바이러스 부분의 시간은 계산하면 안된다!
	int t = 0;
	int flag = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				// 빈칸인데 방문하지 않았으면
				if (visited[i][j] == -1) {
					flag = 0;
					break;
				}
				// 빈칸인데 방문한 곳이라면
				else
					// 최댓값 갱신
					t = max(t, visited[i][j]);
			}
		}
	}
	if (flag)
		MIN = min(MIN, t);
}

void dfs(int level, int si) {
	if (level == m) {

		queue<node> q;
		
		// visited 초기화
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = -1;
			}
		}

		// bfs돌릴 queue 생성 및 초기 바이러스 위치 설정
		for (int i = 0; i < path.size(); i++) {
			q.push(path[i]);
			visited[path[i].y][path[i].x] = 0;
		}

		bfs(q);

		return;
	}

	for (int i = si; i < virusV.size(); i++) {

		path.push_back(virusV[i]);
		dfs(level + 1, i + 1);
		path.pop_back();

	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int flag0 = 0;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {

		cin >> arr[i][j];

		if (arr[i][j] == 2) virusV.push_back({ i, j });

		if (arr[i][j] == 0) flag0 = 1;

	}
	if (!flag0) {
		// 빈칸이 한 곳도 없는 경우
		cout << 0;
		return 0;
	}

	dfs(0, 0);

	if (MIN == 987654321) cout << -1;
	else cout << MIN;

	return 0;
}
