#include <iostream>

using namespace std;

struct node {
	int y, x;
};
node red, blue;
int n, m;
char arr[11][11];
int d[2][4] = {
	-1, 0, 1, 0,
	0, 1, 0, -1
};
int ans = 987654321;
int backd[4] = {
	2, 3, 0, 1
};
void init();

void move9(int redX, int redY, int blueX, int blueY, int cnt, int dir) {
	if (cnt >= ans) return;
	if (cnt >= 10) return;

	int redDy = redY + d[0][dir];
	int redDx = redX + d[1][dir];
	int blueDy = blueY + d[0][dir];
	int blueDx = blueX + d[1][dir];
	
	int redFlag = 0;
	int blueFlag = 0;
	//red 이동
	while (1) {
		// 이동한 지점이 벽이면 패스
		if (arr[redDy][redDx] == '#') break;
		// 구멍을 만나면 체크
		if (arr[redDy][redDx] == 'O') {
			redFlag = 1;
			break;
		}
		redDy += d[0][dir];
		redDx += d[1][dir];
	}
	// 무조건 하나씩 앞서가기때문에 하나 빼줘야함
	redDy -= d[0][dir];
	redDx -= d[1][dir];

	//blue 이동
	while (1) {
		// 이동한 지점이 벽이면 패스
		if (arr[blueDy][blueDx] == '#') break;
		// 구멍을 만나면 체크
		if (arr[blueDy][blueDx] == 'O') {
			blueFlag = 1;
			break;
		}
		blueDy += d[0][dir];
		blueDx += d[1][dir];
	}
	// 무조건 하나씩 앞서가기때문에 하나 빼줘야함
	blueDy -= d[0][dir];
	blueDx -= d[1][dir];

	if (blueFlag == 1) return;
	else {
		if (redFlag == 1) {
			ans = min(ans, cnt);
			return;
		}
	}
	// 구슬이 겹치면 안된다!!!
	if (redDy == blueDy and redDx == blueDx) {
		// 구슬이 겹칠경우 이동거리가 더 길었던 친구를 1 빼준다
		int rd = abs(redDy - redY) + abs(redDx - redX);
		int bd = abs(blueDy - blueY) + abs(blueDx - blueX);
		if (rd > bd) {
			redDy -= d[0][dir];
			redDx -= d[1][dir];
		}
		else {
			blueDy -= d[0][dir];
			blueDx -= d[1][dir];
		}
	}

	for (int direction = 0; direction < 4; direction++) {
		if (dir == direction) continue;
		if (backd[dir] == direction) continue;
		// 재귀 실행
		move9(redDx, redDy, blueDx, blueDy, cnt + 1, direction);
	}
}

void solved() {

	for (int dir = 0; dir < 4; dir++) {
		int redX = red.x;
		int redY = red.y;
		int blueX = blue.x;
		int blueY = blue.y;

		move9(redX, redY, blueX, blueY, 0, dir);
	}

	if (ans == 987654321) cout << -1;
	else cout << ans + 1;
}

int main() {

	init();
	solved();
	return 0;
}

void init() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char input;
			cin >> input;
			if (input == 'B') {
				blue = { i, j };
				arr[i][j] = '.';
			}
			else if (input == 'R') {
				red = { i, j };
				arr[i][j] = '.';
			}
			else arr[i][j] = input;
		}
	}
}