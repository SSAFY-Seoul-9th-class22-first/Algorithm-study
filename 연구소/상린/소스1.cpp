#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

/*
설계

벽을 총 3개 세우기 ->

왜이래
2 1 0 0 1 1 0
1 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 1 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

2 1 2 2 1 1 2
1 0 1 2 1 2 2
2 1 1 2 1 2 2
2 1 2 2 2 1 2
2 2 2 2 2 1 1
2 1 2 2 2 2 2
2 1 2 2 2 2 2
1

*/

struct Node {
	int y;
	int x;
};

int N, M;
int MAP[8][8];
int C_MAP[8][8];

int visited[8][8]; // floodfill의 visited

Node wall[3];
int ans = 0;

int Dr[2][4] = {
	-1,0,0,1,
	0,-1,1,0,
};

void FloodFill(int sy, int sx)
{
	// 2에서 시작이고, 0을 만나면 2로 바꾸기, 1이면 못가
	queue<int> qy;
	queue<int> qx;

	qy.push(sy); qx.push(sx);

	while (!qy.empty())
	{
		int nowy = qy.front(); qy.pop();
		int nowx = qx.front(); qx.pop();

		// 네 방향으로
		for (int i = 0; i < 4; i++)
		{
			int nexty = nowy + Dr[0][i];
			int nextx = nowx + Dr[1][i];

			if (nexty<0 || nexty>=N || nextx<0 || nextx>=M) continue;
			// 1벽 이면 X
			if (C_MAP[nexty][nextx] == 1) continue;
			// 방문했으면 X
			if (visited[nexty][nextx] == 1) continue;

			C_MAP[nexty][nextx] = 2;
			visited[nexty][nextx] = 1;

			qy.push(nexty);
			qx.push(nextx);
		}
	}
}


// 안전영역의 크기를 return
int Virus()
{
	// visited초기화
	memset(visited, 0, sizeof(visited));
	// 맵 복사
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			C_MAP[i][j] = MAP[i][j];
			//cout << C_MAP[i][j] << " ";
		}
		//cout << endl;
	}
	//cout << endl;
	// 모든 virus에서 floodfill 돌리기 -> visited가 없는 2를 찾아서 돌리기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (C_MAP[i][j] == 2 && visited[i][j] == 0)
			{
				// floodfill 돌리기
				FloodFill(i, j);
			}
		}
	}

	// 0의 개수를 return
	int rst = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (C_MAP[i][j] == 0) rst++;
			//cout << C_MAP[i][j] << " ";
		}
		//cout << endl;
	}
	//cout << rst << endl;
	return rst;
}

void DFS(int now)
{
	if (now == 3)
	{
		ans = max(ans, Virus());

		return;
	}


	// 세개 선택하기 (빈칸좌표중)
	for (int i = 0; i < N; i++)
	{
		if (now != 0)
			if (wall[now - 1].y > i) continue;
		for (int j = 0; j < M; j++)
		{
			if (now != 0)
				if (wall[now - 1].y == i && wall[now - 1].x >= j) continue;

			if (MAP[i][j] == 0)
			{
				wall[now] = { i,j };
				MAP[i][j] = 1;
				DFS(now + 1);
				MAP[i][j] = 0;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j]; // 0빈칸 1벽 2바이러스 (2<= <=10)
		}
	}/*
	cout << endl;*/

	// DFS 로 빈칸들중에 3개 선택하기
	DFS(0);
	// 출력 : 얻을 수 있는 안전영역의 최대
	cout << ans;

	return 0;
}