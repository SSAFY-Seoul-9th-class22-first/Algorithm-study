#include <iostream>
using namespace std;

int N, M;
int MAP[501][501] = {};
int path[5] = {};
int mx = 0;
int start_x = 0;
int start_y = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int visited[501][501] = {};

void dfs(int x, int y, int level) {
	if (level == 3) {
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			sum += path[i];
		}
		if (mx < sum) mx = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (visited[nx][ny] == 1) continue;
		visited[nx][ny] = 1;
		path[level + 1] = MAP[nx][ny];
		dfs(nx, ny, level + 1);
		path[level + 1] = 0;
		visited[nx][ny] = 0;
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
			visited[i][j] = 1;
			path[0] = MAP[i][j];
			dfs(i, j, 0);
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 2; j++) {
			int sum = MAP[i][j] + MAP[i][j + 1] + MAP[i][j + 2] + MAP[i + 1][j + 1];
			if (mx < sum) mx = sum;
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M - 2; j++) {
			int sum = MAP[i][j] + MAP[i][j + 1] + MAP[i][j + 2] + MAP[i - 1][j + 1];
			if (mx < sum) mx = sum;
		}
	}
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			int sum = MAP[i][j] + MAP[i][j + 1] + MAP[i - 1][j + 1] + MAP[i + 1][j + 1];
			if (mx < sum) mx = sum;
		}
	}
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M; j++) {
			int sum = MAP[i][j] + MAP[i][j - 1] + MAP[i - 1][j - 1] + MAP[i + 1][j - 1];
			if (mx < sum) mx = sum;
		}
	}

	cout << mx;
}