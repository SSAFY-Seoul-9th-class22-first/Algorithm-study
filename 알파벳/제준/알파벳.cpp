#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int R, C;
char MAP[22][22];
int visited[22][22];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int DAT[100];
int mx = 1;

void dfs(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
		if (DAT[MAP[nx][ny]] != 0) continue;
		if (visited[nx][ny] != 0) continue;

		DAT[MAP[nx][ny]]++;
		visited[nx][ny] = visited[x][y] + 1;
		if (mx < visited[nx][ny]) mx = visited[nx][ny];

		dfs(nx, ny);

		visited[nx][ny] = 0;
		DAT[MAP[nx][ny]] = 0;
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> MAP[i];
	}

	visited[0][0] = 1;
	DAT[MAP[0][0]]++;
	dfs(0, 0);

	cout << mx;
}