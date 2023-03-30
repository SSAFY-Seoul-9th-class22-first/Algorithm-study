#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

/*
�մ� ������ �������ָ� ���� ���� -> 
M���� �°� �¿�°� ��ǥ
�����¿� ������ ��ĭ���ϳ��� �̵�.->�ִܰ��
���� �ý���ġ���� �ִܰŸ��� ����ª�� �°���
- ���� ������? ���ȣ ���� ��, ����ȣ ������
��ĭ�� 1 �Ҹ�
������ �̵��Ϸ� -> �°����¿� �̵��ϸ鼭 �Ҹ����� ���� *2 ����
�̵��ϴ� ���߿� ���� ����? ����.
�°��� �������� �̵���Ŵ���ÿ� ���� ��? ����.
*/
struct person {
	int sy, sx, gy, gx;
	int distTaxi;
	int distGoal;
};
int M, N;
int ty, tx;
int E;
int map[21][21];
vector <person> pv;
int visited[21][21];

bool comp(person a, person b)
{
	if (a.distTaxi < b.distTaxi)
		return true;
	if (a.distTaxi > b.distTaxi)
		return false;
	if (a.sy < b.sy)
		return true;
	if (a.sy > b.sy)
		return false;
	if (a.sx < b.sx)
		return true;
	if (a.sx > b.sx)
		return false;
}

void BFS(int ty, int tx)
{
	int dy[] = { -1,0,1,0 };
	int dx[] = { 0,1,0,-1 };

	visited[ty][tx] = 1;
	queue <pair<int, int>> q;
	q.push({ ty,tx });

	while (!q.empty())
	{
		int nowy = q.front().first ;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nexty = nowy + dy[i];
			int nextx = nowx + dx[i];

			if (nexty<1 || nextx<1 || nexty>N || nextx>N) continue;
			if (visited[nexty][nextx] != 0)
				continue;
			if (map[nexty][nextx] == 1)
				continue;


			visited[nexty][nextx] = visited[nowy][nowx] + 1;
			q.push({ nexty,nextx });
		}

	}
}


int main()
{
	cin >> N >> M >> E;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	cin >> ty >> tx;
	//�ʹ� ����.
	
	for (int i = 0; i < M; i++)
	{
		int sy, sx, gy, gx;
		cin >> sy >> sx >> gy >> gx;
		pv.push_back({ sy,sx,gy,gx,visited[sy][sx],0});
	}
	//����  �¿� �°� ���ϱ�.
	


	
	bool FAIL = false;
	while(1)
	{
		if (E <= 0)
		{
			break;
		}
		if (pv.size() == 0)
		{
		
			break;
		}
		memset(visited, 0, sizeof(visited));
		//�׶��׶� ���¿� �°����ϱ�.
		//taxi -> �°� ������ �Ÿ� ���ϱ�
		BFS(ty, tx);
		for (int i = 0; i < pv.size(); i++)
		{
			pv[i].distTaxi = visited[pv[i].sy][pv[i].sx] - 1;
		}

		/*
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << visited[i][j] << " ";
			}
			cout << endl;
		}
		*/
		//���� ���������� ����.
		if (pv[0].distTaxi==-1)
		{
			FAIL = true;
			break;
		}
		//�Ÿ� -> �� -> �� ������ ����
		sort(pv.begin(), pv.end(), comp);
		
		
		//���� - (taxi->�°��Ÿ�)
		E -= pv[0].distTaxi;

		//BFS �ٽ� �����Ŷ� �ʱ�ȭ
		//�̹��� �°�-> ������ �Ÿ�
		memset(visited, 0, sizeof(visited));
		BFS(pv[0].sy, pv[0].sx);
		pv[0].distGoal = visited[pv[0].gy][pv[0].gx]-1;
		E -= pv[0].distGoal;

		//���� ������ ������
		if (E < 0)
		{
			FAIL = true;
			break;
		}//���������ÿ� ���� ���Ǵ°� �������̽�
		else 
			E += (pv[0].distGoal * 2);

		ty = pv[0].gy;
		tx = pv[0].gx;
		//���� �տ� ���� ���ֱ�
		pv.erase(pv.begin());
	}

	if (FAIL)
		cout << -1;
	else
		cout << E;
	return 0;
}
