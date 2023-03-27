#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ball {
	int m, d, s;
};

struct node {
	int y, x;
};

int d[2][8] = {
	-1, -1, 0, 1, 1,  1,  0, -1,
	 0,  1, 1, 1, 0, -1, -1, -1
};

int cd[2][4] = {
	0, 2, 4, 6,
	1, 3, 5, 7
};

int N, M, K;
queue<ball> arr[51][51];
queue<node> q;

void moveFire() {
	
	while (!q.empty()) {
		node now = q.front();
		ball nowBall = arr[now.y][now.x].front();
		q.pop(); arr[now.y][now.x].pop();

		int dy = now.y; int dx = now.x;

		for (int i = 0; i < nowBall.s; i++) {
			dy += d[0][nowBall.d]; dx += d[1][nowBall.d];
			if (dy == N + 1) dy = 1;
			if (dx == N + 1) dx = 1;
			if (dy == 0) dy = N;
			if (dx == 0) dx = N;
		}
		arr[dy][dx].push(nowBall);
	}
}

int overFind() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j].size() == 0) continue;
			else if (arr[i][j].size() == 1) {
				q.push({ i, j });
				ans += arr[i][j].front().m;
			}
			// 2개 이상 파이어볼이 존재한다면
			else if (arr[i][j].size() > 1) {

				int sumM = 0; int sumS = 0;
				int ballCnt = arr[i][j].size();
				int flag1 = 0; int flag2 = 0;

				while (!arr[i][j].empty()) {
					ball nowBall = arr[i][j].front();
					arr[i][j].pop();
					sumM += nowBall.m;
					sumS += nowBall.s;
					if (nowBall.d % 2 == 0) flag2 = 1;
					else flag1 = 1;

				}
				sumS = sumS / ballCnt;
				if (sumM / 5 > 0) {
					ans += sumM / 5 * 4;
					if ((flag1 == 1 and flag2 == 0)
						or (flag1 == 0 and flag2 == 1)) {
						for (int dir = 0; dir < 4; dir++) {
							q.push({ i, j });
							arr[i][j].push({ sumM / 5, cd[0][dir], sumS });
						}
					}
					else {
						for (int dir = 0; dir < 4; dir++) {
							q.push({ i, j });
							arr[i][j].push({ sumM / 5, cd[1][dir], sumS });
						}
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		q.push({ r,c });
		arr[r][c].push({ m, d, s });
	}


	int ans = 0;
	while (K--) {
		moveFire();
		ans = overFind();
	}
	
	cout << ans;
	return 0;
}