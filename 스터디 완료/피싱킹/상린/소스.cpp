#include<iostream>

using namespace std;

/*
반례
2 3 2
1 3 75 4 7
1 2 75 4 6

output : 0
answer : 7


4 3 3
3 3 32 1 7
1 3 32 1 2
3 1 32 1 3

output : 5
answer : 10


3 3 2
2 3 77 1 8
1 3 77 1 4

output : 4
answer : 8
*/

struct sea {
	int s=0, d=0, z=0, now=0; // now 움직였는지 판단
};

int Dr[2][4] = {
	-1,1,0,0,
	0,0,1,-1,
}; // d(1위 2아래 3오른쪽 4왼쪽)

int rev[4] = { 1,0,3,2 };

sea MAP[100][100];
int sum;

int main()
{
	int R, C, M; cin >> R >> C >> M; // 격자판크기R,C 상어수M

	for (int i = 0;i < M;i++)
	{
		int r, c, s, d, z; cin >> r >> c >> s >> d >> z;
		MAP[r-1][c-1] = { s,d-1,z,0 }; // r,c,s,d,z : 상어위치(r,c) s속력 d이동방향 z크기
	}

	// 낚시왕이 모든 열을 다 돌 때 까지
	for (int t = 0;t < C;t++)
	{
		// 1. 해당 열에 있는 상어 중 가장 가까운 상어 잡아
		for (int i = 0;i < R;i++)
		{
			if (MAP[i][t].now == t && MAP[i][t].z != 0)
			{
				sum += MAP[i][t].z;
				MAP[i][t].z = 0;
				break;
			}
		}

		// 2. 상어 이동 - 경계 넘으면 방향만 반대로 바꾸기 - 상어 같은칸 : 크기가 큰 상어가 남게됨
		for (int i = 0;i < R;i++)
		{
			for (int j = 0;j < C;j++)
			{
				if (MAP[i][j].z != 0 && MAP[i][j].now == t)
				{
					int offsetR = 2 * (R - 1);
					int offsetC = 2 * (C - 1);
					// 속력만큼 이동방향으로 움직이기
					int ny;
					if (offsetR == 0) ny = i;
					else ny = abs((i + Dr[0][MAP[i][j].d] * MAP[i][j].s) % offsetR);
					int nx;
					if (offsetC == 0) nx = j;
					else nx = abs((j + Dr[1][MAP[i][j].d] * MAP[i][j].s) % offsetC);

					if (ny >= R)
					{
						ny = 2 * R - ny - 2;
						MAP[i][j].d = rev[MAP[i][j].d];
					}
					if (nx >= C)
					{
						nx = 2 * C - nx - 2;
						MAP[i][j].d = rev[MAP[i][j].d];
					}

					// 해당 칸에 이미 움직여서 있다면 
					if ((MAP[ny][nx].now == t + 1) && (MAP[ny][nx].z > MAP[i][j].z)) continue;

					// 해당칸으로 들어가
					MAP[ny][nx] = MAP[i][j];
					MAP[ny][nx].now = t + 1;
				}
			}
		}
	}

	// 출력 : 낚시왕이 잡은 상어 크기의 합
	cout << sum;

	return 0;
}
