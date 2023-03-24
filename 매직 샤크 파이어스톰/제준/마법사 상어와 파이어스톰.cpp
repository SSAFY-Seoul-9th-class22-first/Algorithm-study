#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int N, Q;
int MAP[130][130] = {};
int MAP_CPY[130][130] = {};
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int visited[130][130] = {};
int mx = 0;

void bfs(int x, int y) {
	int total = 1;
	visited[x][y] = 1;
	queue<pair<int, int>> q;
	q.push({ x, y });
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= (1 << N) || ny >= (1 << N)) continue;
			if (visited[nx][ny] == 1) continue;
			if (MAP[nx][ny] == 0) continue;
			visited[nx][ny] = 1;
			total++;
			q.push({ nx, ny });
		}
	}

	if (total > mx) mx = total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) {
			cin >> MAP[i][j];
		}
	}

	vector<int> vec;
	for (int i = 0; i < Q; i++) {
		int level;
		cin >> level;
		vec.push_back(level);
	}

	int cnt = -1;
	while (Q--) {
		cnt++;

		for (int i = 0; i < (1 << (N - vec[cnt])); i++) {
			for (int j = 0; j < (1 << (N - vec[cnt])); j++) {
				// 가장 왼쪽 위 지점
				int x = i * (1 << (vec[cnt]));
				int y = j * (1 << (vec[cnt]));
				for (int k = 0; k < (1 << (vec[cnt])); k++) {
					for (int l = 0; l < (1 << (vec[cnt])); l++) {
						int x_point = x + k;
						int y_point = y + l;
						MAP_CPY[x + l][y + (1 << (vec[cnt])) - 1 - k] = MAP[x_point][y_point];
					}
				}
			}
		}

		for (int i = 0; i < (1 << N); i++) {
			for (int j = 0; j < (1 << N); j++) {
				MAP[i][j] = MAP_CPY[i][j];
			}
		}


		for (int i = 0; i < (1 << N); i++) {
			for (int j = 0; j < (1 << N); j++) {
				int temp_cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= (1 << N) || ny >= (1 << N)) continue;
					if (MAP[nx][ny] == 0) continue;
					temp_cnt++;
				}
				if (temp_cnt < 3) {
					if (MAP[i][j] == 0) MAP_CPY[i][j] = MAP[i][j];
					else MAP_CPY[i][j] = MAP[i][j] - 1;
				}
				else {
					MAP_CPY[i][j] = MAP[i][j];
				}
			}
		}

		for (int i = 0; i < (1 << N); i++) {
			for (int j = 0; j < (1 << N); j++) {
				MAP[i][j] = MAP_CPY[i][j];
			}
		}

	}

	int sum = 0;
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) {
			sum += MAP[i][j];
		}
	}

	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) {
			if (visited[i][j] == 1) continue;
			if (MAP[i][j] == 0) continue;
			bfs(i, j);
		}
	}

	cout << sum << '\n';
	cout << mx;
}