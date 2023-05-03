#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct node {
	int y, x;
};

int n, m;
node nowNode;

int d[2][4] = {
	-1, 0, 1, 0,
	0, 1, 0, -1
};
int visited[55][55][65];

char arr[55][55];

void bfs(node startNode, int distance, int key) {
	queue<node> q;
	q.push(startNode);
	visited[startNode.y][startNode.x][key] = distance + 1;

	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int dy = now.y + d[0][dir];
			int dx = now.x + d[1][dir];
			if (dy < 0 || dx < 0 || dy >= n || dx >= m) continue;
			if (arr[dy][dx] == '#') continue;

			// 문인 경우
			if (arr[dy][dx] >= 'A' && arr[dy][dx] <= 'Z') {
				int k = arr[dy][dx] - 'A';
				if (key & (1 << k)) {
					if (visited[dy][dx][key] == 0 || 
						visited[dy][dx][key] > visited[now.y][now.x][key] + 1) {
						char saveChar = arr[dy][dx];
						arr[dy][dx] = '.';
						node nextNode = { dy, dx };
						bfs(nextNode, visited[now.y][now.x][key], key);
						arr[dy][dx] = saveChar;
					}
				}
			}

			// 열쇠인 경우
			else if (arr[dy][dx] >= 'a' && arr[dy][dx] <= 'z') {
				int k = arr[dy][dx] - 'a';
				int nextKey = key | (1 << k);

				if (visited[dy][dx][nextKey] == 0 || 
					visited[dy][dx][nextKey] > visited[now.y][now.x][key] + 1) {
					node nextNode = { dy, dx };
					bfs(nextNode, visited[now.y][now.x][key], nextKey);
				}
			}

			// 빈칸인 경우
			else {
				if (visited[dy][dx][key] == 0 || 
					visited[dy][dx][key] > visited[now.y][now.x][key] + 1) {
					q.push({ dy, dx });
					visited[dy][dx][key] = visited[now.y][now.x][key] + 1;
				}
			}

		}

	}
}

int main() {

	// 빈칸 .
	// 벽 #
	// 열쇠 소문자
	// 문 대문자
	// O 민식이 현재 위치
	// 출구 1
	// 열쇠를 가지고 있는 경우의 수에 대한 bfs를 다 돌려줘야함!
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '0') {
				nowNode = { i, j };
			}
		}
	}
	bfs(nowNode, 0, 0);
	int ans = 987654321; 
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (arr[y][x] == '1') {
				for (int i = 0; i < 64; i++) {
					if (visited[y][x][i] > 0) {
						ans = min(ans, visited[y][x][i] - 1);
					}
				}
			}
		}
	}

	if (ans == 987654321) ans = -1;
	cout << ans;

	return 0;
}