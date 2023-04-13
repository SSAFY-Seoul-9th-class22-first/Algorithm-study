#include <iostream>

using namespace std;

int arr[22][22];
// 위 아래 동 서 북 남
int dice[6];
int d[2][5] = {
	0, 0, 0, -1, 1,
	0, 1, -1, 0, 0
};

void moveDice(int dir) {
	int copyDice[6] = { 0 };
	for (int i = 0; i < 6; i++) {
		copyDice[i] = dice[i];
	}
	//동 서 북 남 1, 2, 3, 4
	if (dir == 1) { // 동
		dice[0] = copyDice[3]; dice[2] = copyDice[0];
		dice[1] = copyDice[2]; dice[3] = copyDice[1];
	}

	else if (dir == 2) { // 서
		dice[0] = copyDice[2]; dice[2] = copyDice[1];
		dice[1] = copyDice[3]; dice[3] = copyDice[0];
	}

	else if (dir == 3) { // 북
		dice[0] = copyDice[5]; dice[4] = copyDice[0];
		dice[1] = copyDice[4]; dice[5] = copyDice[1];
	}

	else if (dir == 4) { // 남
		dice[0] = copyDice[4]; dice[4] = copyDice[1];
		dice[1] = copyDice[5]; dice[5] = copyDice[0];
	}
}

int main() {
	
	int n, m, y, x, k;
	cin >> n >> m >> y >> x >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int dir; cin >> dir;
		int dy = y + d[0][dir]; int dx = x + d[1][dir];
		if (dy < 0 or dx < 0 or dy == n or dx == m) continue;
		moveDice(dir);

		if (arr[dy][dx] == 0) {
			arr[dy][dx] = dice[1];
		}
		else {
			dice[1] = arr[dy][dx];
			arr[dy][dx] = 0;
 		}
		cout << dice[0] << endl;
		y = dy; x = dx;
	}
	return 0;
}