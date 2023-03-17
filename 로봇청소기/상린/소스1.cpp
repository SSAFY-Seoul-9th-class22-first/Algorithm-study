#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

/*
빈칸 -> 청소

1. 주변 네칸 중 청소되지 않은 빈칸이 있다면
반시계방향으로 회전 -> -1 -1이되면 3 -> 전진해서 청소
2. 주변 네칸이 모두 청소된 빈칸이라면
바라보는 방향 기준 후진 -> 1번으로가기
후진이 벽이라 후진 못한다면 작동 멈추기

*/

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
		// 맵 출력해보기
		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < M; j++)
		//		cout << MAP[i][j];
		//	cout << endl;
		//}
		//cout << ans << endl;


		// 1. 현재 칸 청소하기
		if (MAP[y][x] == 0)
		{
			ans++;
			MAP[y][x] = -1;
		}
		// 다음 청소할 칸 정하기

		// 1. 반시계로 회전하기

		int flag = 0;
		for (int i = 1; i <= 4; i++)
		{
			// 청소되지 않은 빈칸 찾기
			int nd = d - i;
			if (nd < 0) nd += 4;

			int ny = y + Dr[0][nd];
			int nx = x + Dr[1][nd];
			//cout << ny << " " << nx << " " << MAP[ny][nx] << endl;
			if (MAP[ny][nx] == 0)
			{
				// 청소되지 않은 빈칸이라면 한칸 전진하기
				y = ny;
				x = nx;
				d = nd;
				flag = 1;
				break;
			}
		}

		// 빈칸이 있는데 못찾고 있다

		if (flag) continue; // 청소할 빈칸 찾았다면 다시 1부터 시작

		// 주변에 청소할 빈칸이없다면

		// 바라보는 방향을 유지한채로 한칸 후진하고 1번으로 돌아가기
		int by = y - Dr[0][d];
		int bx = x - Dr[1][d];


		// 벽이라면 작동 멈추기
		if (by < 0 || by >= N || bx < 0 || bx >= M) break;
		if (MAP[by][bx] == 1) break;

		y = by;
		x = bx;
	}

	// 출력 : 청소하는 칸의 갯수
	cout << ans;

	return 0;
}