#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct node {
	int y, x;
};
int n, m;
int arr[8][8];
vector<node> v;
vector<node> vec;
int d[2][4] = {
	-1, 0, 1, 0,
	0, 1, 0, -1
};
int MIN = 987654321;

void full(int y, int x, int dir) {
	int dy = y + d[0][dir]; int dx = x + d[1][dir];
	while (1) {
		if (dy < 0 or dx < 0 or dy == n or dx == m) break;
		if (arr[dy][dx] == 6) break;
		if (arr[dy][dx] == 0) {
			arr[dy][dx] = -1;
		}
		dy += d[0][dir]; dx += d[1][dir];
	}
}

void fullArr(int y, int x, int cctv, int direction) {
	if (cctv == 1) {
		full(y, x, direction);
	}
	else if (cctv == 2) {
		full(y, x, direction);
		full(y, x, direction + 2);
	}
	else if (cctv == 3) {
		full(y, x, direction);
		full(y, x, (direction + 1) % 4);
	}
	else if (cctv == 4) {
		full(y, x, direction);
		full(y, x, (direction + 1) % 4);
		full(y, x, (direction + 2) % 4);
	}
}

void dfs(int level) {
	if (level == vec.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) {
					cnt++;
				}
			}
		}
		if (MIN > cnt)MIN = cnt;
		return;
	}
	int copyArr[8][8] = { 0, };
	node now = vec[level];
	int cctv = arr[now.y][now.x];
	if (cctv == 2) {
		for (int i = 0; i < 2; i++) {
			//세로 가로
			memcpy(&copyArr, &arr, sizeof(arr));
			fullArr(now.y, now.x, cctv, i);
			dfs(level + 1);
			memcpy(&arr, &copyArr, sizeof(copyArr));
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			// 4가지 방향
			memcpy(&copyArr, &arr, sizeof(arr));
			fullArr(now.y, now.x, cctv, i);
			dfs(level + 1);
			memcpy(&arr, &copyArr, sizeof(copyArr));
		}

	}
}
int main() {

	// 0은 빈 칸, 6은 벽, 1~5는 cctv
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
		cin >> arr[i][j];
		if (arr[i][j] > 0 and arr[i][j] < 5) {
			vec.push_back({ i, j });
		}
		if (arr[i][j] == 5) {
			v.push_back({ i, j });
		}
	}
	// 5번 cctv 먼저 설정
	for (int i = 0; i < v.size(); i++) {
		node now = v[i];
		for (int dir = 0; dir < 4; dir++) {
			int dy = now.y + d[0][dir]; int dx = now.x + d[1][dir];
			while (1) {
				if (dy < 0 or dx < 0 or dy == n or dx == m) break;
				if (arr[dy][dx] == 6) break;
				if (arr[dy][dx] == 0) {
					arr[dy][dx] = -1;
				}
				dy += d[0][dir]; dx += d[1][dir];

			}
		}
	}

	dfs(0);
	cout << MIN;
	return 0;
}