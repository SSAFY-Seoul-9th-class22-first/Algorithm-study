#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int N, M; cin >> N >> M;

	int y, x, d; cin >> y >> x >> d;
	// d : 0북 1동 2남 3서

	int Dr[2][4] = {
		-1,0,1,0,
		0,1,0,-1,
	};

	int MAP[50][50];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j]; // 0청소X빈칸 1벽 -1청소O빈칸
		}
	}

	// 청소기 작동하기
	int ans = 0;
	while (1)
	{
		// 1. 현재 칸 청소하기
		if (MAP[y][x] == 0)
		{
			ans++;
			MAP[y][x] = -1;
		}

		// 1. 반시계로 회전하기

		int flag = 0;
		for (int i = 1; i <= 4; i++)
		{
			// 청소되지 않은 빈칸 찾기
			int nd = d - i;
			if (nd < 0) nd += 4;

			int ny = y + Dr[0][nd];
			int nx = x + Dr[1][nd];
			if (MAP[ny][nx] == 0)
			{
				y = ny;
				x = nx;
				d = nd;
				flag = 1;
				break;
			}
		}

		if (flag) continue; // 청소할 빈칸 찾았다면 다시 1부터 시작

		// 바라보는 방향을 유지한채로 한칸 후진하고 1번으로 돌아가기
		int by = y - Dr[0][d];
		int bx = x - Dr[1][d];

		// 벽이라면 작동 멈추기
		if (by < 0 || by >= N || bx < 0 || bx >= M) break;
		if (MAP[by][bx] == 1) break;

		y = by; x = bx;
	}

	// 출력 : 청소하는 칸의 갯수
	cout << ans;

	return 0;
}