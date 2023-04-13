#include <iostream>
#include <vector>
using namespace std;

int N, M;
int MAP[9][9] = {};
int visible[9][9] = {};

struct Node {
	int x;
	int y;
	int num;
};

vector<Node> vec;
int vec_size = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int mn = 21e8;

void dfs(int level) {
	if (level == vec_size) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (MAP[i][j] == 0 && visible[i][j] == 0) cnt++;
			}
		}
		if (mn > cnt) mn = cnt;
		return;
	}

	if (MAP[vec[level].x][vec[level].y] == 1) {
		for (int i = 0; i < 4; i++) {
			vector<pair<int, int>> vect;
			for (int j = 1; j <= 10; j++) {
				int nx = vec[level].x + dx[i] * j;
				int ny = vec[level].y + dy[i] * j;
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (MAP[nx][ny] == 6) break;
				visible[nx][ny]++;
				vect.push_back({ nx, ny });
			}
			dfs(level + 1);
			for (int j = 0; j < vect.size(); j++) {
				visible[vect[j].first][vect[j].second]--;
			}

		}
	}
	if (MAP[vec[level].x][vec[level].y] == 2) {
		for (int i = 0; i < 2; i++) {
			vector<pair<int, int>> vect;
			for (int j = 1; j <= 10; j++) {
				int nx = vec[level].x + dx[i] * j;
				int ny = vec[level].y + dy[i] * j;
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (MAP[nx][ny] == 6) break;
				visible[nx][ny]++;
				vect.push_back({ nx, ny });
			}
			for (int j = 1; j <= 10; j++) {
				int nx = vec[level].x + dx[i + 2] * j;
				int ny = vec[level].y + dy[i + 2] * j;
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (MAP[nx][ny] == 6) break;
				visible[nx][ny]++;
				vect.push_back({ nx, ny });
			}
			dfs(level + 1);
			for (int j = 0; j < vect.size(); j++) {
				visible[vect[j].first][vect[j].second]--;
			}
		}
	}
	if (MAP[vec[level].x][vec[level].y] == 3) {
		for (int i = 0; i < 4; i++) {
			vector<pair<int, int>> vect;
			for (int j = 1; j <= 10; j++) {
				int nx = vec[level].x + dx[i] * j;
				int ny = vec[level].y + dy[i] * j;
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (MAP[nx][ny] == 6) break;
				visible[nx][ny]++;
				vect.push_back({ nx, ny });
			}
			for (int j = 1; j <= 10; j++) {
				int nx = vec[level].x + dx[(i + 1) % 4] * j;
				int ny = vec[level].y + dy[(i + 1) % 4] * j;
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (MAP[nx][ny] == 6) break;
				visible[nx][ny]++;
				vect.push_back({ nx, ny });
			}
			dfs(level + 1);
			for (int j = 0; j < vect.size(); j++) {
				visible[vect[j].first][vect[j].second]--;
			}

		}
	}
	if (MAP[vec[level].x][vec[level].y] == 4) {
		for (int i = 0; i < 4; i++) {
			vector<pair<int, int>> vect;
			for (int j = 1; j <= 10; j++) {
				int nx = vec[level].x + dx[i] * j;
				int ny = vec[level].y + dy[i] * j;
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (MAP[nx][ny] == 6) break;
				visible[nx][ny]++;
				vect.push_back({ nx, ny });
			}
			for (int j = 1; j <= 10; j++) {
				int nx = vec[level].x + dx[(i + 1) % 4] * j;
				int ny = vec[level].y + dy[(i + 1) % 4] * j;
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (MAP[nx][ny] == 6) break;
				visible[nx][ny]++;
				vect.push_back({ nx, ny });
			}
			for (int j = 1; j <= 10; j++) {
				int nx = vec[level].x + dx[(i + 2) % 4] * j;
				int ny = vec[level].y + dy[(i + 2) % 4] * j;
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (MAP[nx][ny] == 6) break;
				visible[nx][ny]++;
				vect.push_back({ nx, ny });
			}
			dfs(level + 1);
			for (int j = 0; j < vect.size(); j++) {
				visible[vect[j].first][vect[j].second]--;
			}

		}
	}
	if (MAP[vec[level].x][vec[level].y] == 5) {
		vector<pair<int, int>> vect;
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= 10; j++) {
				int nx = vec[level].x + dx[i] * j;
				int ny = vec[level].y + dy[i] * j;
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (MAP[nx][ny] == 6) break;
				visible[nx][ny]++;
				vect.push_back({ nx, ny });
			}
		}

		dfs(level + 1);
		for (int j = 0; j < vect.size(); j++) {
			visible[vect[j].first][vect[j].second]--;
		}
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
			if (MAP[i][j] >= 1 && MAP[i][j] <= 5) {
				vec.push_back({ i, j, MAP[i][j] });
			}
		}
	}

	vec_size = vec.size();
	dfs(0);

	cout << mn;
}