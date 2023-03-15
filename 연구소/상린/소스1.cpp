#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

/*
����

���� �� 3�� ����� ->

���̷�
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

int visited[8][8]; // floodfill�� visited

Node wall[3];
int ans = 0;

int Dr[2][4] = {
	-1,0,0,1,
	0,-1,1,0,
};

void FloodFill(int sy, int sx)
{
	// 2���� �����̰�, 0�� ������ 2�� �ٲٱ�, 1�̸� ����
	queue<int> qy;
	queue<int> qx;

	qy.push(sy); qx.push(sx);

	while (!qy.empty())
	{
		int nowy = qy.front(); qy.pop();
		int nowx = qx.front(); qx.pop();

		// �� ��������
		for (int i = 0; i < 4; i++)
		{
			int nexty = nowy + Dr[0][i];
			int nextx = nowx + Dr[1][i];

			if (nexty<0 || nexty>=N || nextx<0 || nextx>=M) continue;
			// 1�� �̸� X
			if (C_MAP[nexty][nextx] == 1) continue;
			// �湮������ X
			if (visited[nexty][nextx] == 1) continue;

			C_MAP[nexty][nextx] = 2;
			visited[nexty][nextx] = 1;

			qy.push(nexty);
			qx.push(nextx);
		}
	}
}


// ���������� ũ�⸦ return
int Virus()
{
	// visited�ʱ�ȭ
	memset(visited, 0, sizeof(visited));
	// �� ����
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
	// ��� virus���� floodfill ������ -> visited�� ���� 2�� ã�Ƽ� ������
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (C_MAP[i][j] == 2 && visited[i][j] == 0)
			{
				// floodfill ������
				FloodFill(i, j);
			}
		}
	}

	// 0�� ������ return
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


	// ���� �����ϱ� (��ĭ��ǥ��)
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
			cin >> MAP[i][j]; // 0��ĭ 1�� 2���̷��� (2<= <=10)
		}
	}/*
	cout << endl;*/

	// DFS �� ��ĭ���߿� 3�� �����ϱ�
	DFS(0);
	// ��� : ���� �� �ִ� ���������� �ִ�
	cout << ans;

	return 0;
}