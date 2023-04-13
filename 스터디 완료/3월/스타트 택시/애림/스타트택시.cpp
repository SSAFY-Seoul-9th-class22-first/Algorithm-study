#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

/*
손님 도착지 데려다주면 연료 충전 -> 
M개의 승객 태우는거 목표
상하좌우 인접한 빈칸중하나로 이동.->최단경로
현재 택시위치에서 최단거리가 가장짧은 승객고름
- 만약 여러명? 행번호 작은 순, 열번호 작은순
한칸당 1 소모
목적지 이동완료 -> 승객을태워 이동하면서 소몽ㅎ나 연료 *2 충전
이동하는 도중에 연료 없어? 실패.
승객을 목적지로 이동시킴동시에 연료 끝? 성공.
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
	//초반 세팅.
	
	for (int i = 0; i < M; i++)
	{
		int sy, sx, gy, gx;
		cin >> sy >> sx >> gy >> gx;
		pv.push_back({ sy,sx,gy,gx,visited[sy][sx],0});
	}
	//먼저  태울 승객 정하기.
	


	
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
		//그때그때 ㄷ태울 승객구하기.
		//taxi -> 승객 각각의 거리 구하기
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
		//벽에 막혀있으면 못감.
		if (pv[0].distTaxi==-1)
		{
			FAIL = true;
			break;
		}
		//거리 -> 행 -> 열 순으로 정렬
		sort(pv.begin(), pv.end(), comp);
		
		
		//연료 - (taxi->승객거리)
		E -= pv[0].distTaxi;

		//BFS 다시 돌릴거라 초기화
		//이번엔 승객-> 목적지 거리
		memset(visited, 0, sizeof(visited));
		BFS(pv[0].sy, pv[0].sx);
		pv[0].distGoal = visited[pv[0].gy][pv[0].gx]-1;
		E -= pv[0].distGoal;

		//연료 없으면 실패임
		if (E < 0)
		{
			FAIL = true;
			break;
		}//도착과동시에 연료 고갈되는건 성공케이스
		else 
			E += (pv[0].distGoal * 2);

		ty = pv[0].gy;
		tx = pv[0].gx;
		//제일 앞에 벡터 없애기
		pv.erase(pv.begin());
	}

	if (FAIL)
		cout << -1;
	else
		cout << E;
	return 0;
}
