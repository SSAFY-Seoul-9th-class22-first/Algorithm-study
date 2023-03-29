#include <iostream>

using namespace std;

int Dr[2][4] = {
	-1,0,0,1,
	0,-1,1,0,
};

struct Node {
	int y;
	int x;
};

int Student[401][401];
int MAP[400][400];

int main()
{
	// input 받으면서 자리 배치
	int N; cin >> N;
	for (int t = 0;t < N * N;t++)
	{
		int S, a, b, c, d;
		cin >> S >> a >> b >> c >> d;

		Student[S][a] = 1; Student[S][b] = 1; Student[S][c] = 1; Student[S][d] = 1;

		Node MIdx;
		int flag = 0;
		int Mlike = 0; int Mempty = 0;
		// 자리 정하기
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < N;j++)
			{
				// 누가 있다면 continue;
				if (MAP[i][j] != 0) continue;
				else if (MAP[i][j] == 0 && !flag)
				{
					// 첫번째 빈자리 저장
					MIdx = { i,j };
					flag = 1;
				}

				int like = 0;
				int empty = 0;
				for (int k = 0;k < 4;k++)
				{
					int nY = i + Dr[0][k];
					int nX = j + Dr[1][k];

					if (nY < 0 || nY >= N || nX < 0 || nX >= N) continue;
					//cout << nY << " " << nX << " " << Student[S][MAP[nY][nX]] << endl;
					if (Student[S][MAP[nY][nX]] == 1) like++;

					if (MAP[nY][nX] == 0) empty++;
				}

				if (Mlike < like)
				{
					// 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
					MIdx = { i,j }; Mlike = like; Mempty = empty;
				}
				else if (Mlike == like && Mempty < empty)
				{
					// 2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
					MIdx = { i,j }; Mlike = like; Mempty = empty;
				}

				// 2번 조건에서 인덱스가 먼저인게 들어가면, 그 후에 같은 값을 비교하지 않으므로 3번 만족
			}
		}

		// 정해진 자리에 배치하기
		MAP[MIdx.y][MIdx.x] = S;
	}

	// 만족도구하기
	int rst = 0;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			int num = 0;
			for (int k = 0;k < 4;k++)
			{
				int nY = i + Dr[0][k];
				int nX = j + Dr[1][k];

				if (nY < 0 || nY >= N || nX < 0 || nX >= N) continue;

				if (Student[MAP[i][j]][MAP[nY][nX]] == 1) num++;
			}
			if (num == 0) continue;

			int temp = 1;
			for (int t = 0;t < num - 1;t++)
				temp *= 10;
			rst += temp;
		}
	}

	cout << rst;

	return 0;
}