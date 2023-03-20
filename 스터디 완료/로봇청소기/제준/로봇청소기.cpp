#include <iostream>

int N, M;
int r, c, k;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int arr[50][50];
bool clean[50][50] = { false, };
int result = 0; // 청소한 칸의 수
int repetition = 1;

void repeat() {
	if (clean[r][c] == false) {
		clean[r][c] = true;
		result++;
	}
	while (repetition <= 4) {
		k += 3;
		int nr = r + dy[k % 4];
		int nc = c + dx[k % 4];
		if (arr[nr][nc] == 0 && clean[nr][nc] == false) {
			result++;
			clean[nr][nc] = true;
			r = nr;
			c = nc;
			repetition = 1;
		}
		else repetition++;
	}

	int dr = r + dy[(k + 2) % 4];
	int dc = c + dx[(k + 2) % 4];
	if (arr[dr][dc] == 1) return;
	else {
		r = dr;
		c = dc;
		repetition = 1;
		repeat();
	}
}

int main() {
	std::cin >> N >> M;
	std::cin >> r >> c >> k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> arr[i][j];
		}
	}
	repeat();
	std::cout << result;
}