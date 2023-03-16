#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int MAP[9][9] = {};
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int MAP_COPY[9][9];
int mx = 0;
vector<pair<int, int>> zero_vec;

void spread_virus(int start_x, int start_y) {
	int visited[9][9] = {};
	queue<pair<int, int>> q;
	visited[start_x][start_y] = 1;
	q.push({ start_x, start_y });
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny] == 1 || MAP_COPY[nx][ny] == 1 || MAP_COPY[nx][ny] == 2) continue;
			visited[nx][ny] = 1;
			MAP_COPY[nx][ny] = 2;
			q.push({ nx, ny });
		}
	}
}

int path[3] = {};

void dfs(int level) {
	if (level == 3) {
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				MAP_COPY[i][j] = MAP[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (MAP_COPY[i][j] == 2) {
					spread_virus(i, j);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (MAP_COPY[i][j] == 0) cnt++;
			}
		}

		if (mx < cnt) mx = cnt;

		return;
	}

	for (int i = 0; i < zero_vec.size(); i++) {
		if (level >= 1 && path[level - 1] >= i) continue;
		MAP[zero_vec[i].first][zero_vec[i].second] = 1;
		path[level] = i;
		dfs(level + 1);
		path[level] = 0;
		MAP[zero_vec[i].first][zero_vec[i].second] = 0;
	}

}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == 0) {
				zero_vec.push_back({ i, j });
			}
		}
	}


	dfs(0);

	cout << mx;


}