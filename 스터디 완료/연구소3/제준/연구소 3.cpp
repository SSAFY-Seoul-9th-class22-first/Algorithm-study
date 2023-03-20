#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int MAP[51][51] = {};
vector<pair<int, int>> vec;
int path[11] = {};
int cnt = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int visited[51][51] = {};
int mn = 21e8;
// 0은 빈 칸, 1은 벽, 2는 비활성 바이러스, 3은 활성 바이러스

int bfs() {
	int time = 0;
	int temp_cnt = cnt;
	queue<pair<int, int>> q;
	for (int i = 0; i < M; i++) {
		visited[vec[path[i]].first][vec[path[i]].second] = 1;
		q.push({ vec[path[i]].first, vec[path[i]].second });
	}
	while (!q.empty()) {
		time++;
		int cursize = q.size();
		for (int i = 0; i < cursize; i++) {
			pair<int, int> now = q.front();
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = now.first + dx[j];
				int ny = now.second + dy[j];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (visited[nx][ny] == 1) continue;
				if (MAP[nx][ny] == 1) continue;
				if (MAP[nx][ny] == 2 && visited[nx][ny] == 0) {
					visited[nx][ny] = 1;
					q.push({ nx, ny });
				}
				if (MAP[nx][ny] == 0 && visited[nx][ny] == 0) {
					visited[nx][ny] = 1;
					temp_cnt--;
					q.push({ nx, ny });
				}
			}
		}
		if (temp_cnt == 0) break;
	}

	if (temp_cnt > 0) time = 10000000;
	return time;
}


void dfs(int level) {
	if (level == M) {
		int result = bfs();
		if (result < mn) mn = result;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = 0;
			}
		}

		return;
	}
	for (int i = 0; i < vec.size(); i++) {
		if (level >= 1 && path[level - 1] >= i) continue;
		MAP[vec[i].first][vec[i].second] = 3;
		path[level] = i;
		dfs(level + 1);
		MAP[vec[i].first][vec[i].second] = 2;
		path[level] = 0;

	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] == 2) vec.push_back({ i,j });
			if (MAP[i][j] == 0) cnt++;
		}
	}

	dfs(0);

	if (mn == 10000000) cout << -1;
	else if (cnt == 0) cout << 0;
	else cout << mn;

}