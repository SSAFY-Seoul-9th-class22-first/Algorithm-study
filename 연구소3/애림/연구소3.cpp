#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int map[51][51];
int res = 21e8;

vector <pair<int, int>> v;
queue < pair<int, int>>q;
vector<pair<int, int>> can_Virus;

int visited[51][51];
int selected[11];

int flag = 0;

void BFS()
{
	for (int i = 0; i < can_Virus.size(); i++)
	{
		q.push({ can_Virus[i].first, can_Virus[i].second });
		visited[can_Virus[i].first][can_Virus[i].second] = 1;
	}

	int dy[] = { -1,0,1,0 };
	int dx[] = { 0,1,0,-1 };
	int q_time = -21e8;;
	while (!q.empty())
	{
		int S = q.size();
		for (int i = 0; i < S; i++)
		{
			int nowy = q.front().first;
			int nowx = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = nowy + dy[i];
				int nx = nowx + dx[i];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N)
					continue;

				if (map[ny][nx] == 1)
					continue;

				if (visited[ny][nx] >= 1)
					continue;


				visited[ny][nx] = visited[nowy][nowx] + 1;
				q.push({ ny,nx });
			}
		}

	}

	flag = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1)
				continue;
			if (map[i][j] == 0)
			{
				if (visited[i][j] == 0)
				{
					flag = 1;
					break;
				}
				else
					q_time = max(q_time, visited[i][j]);
			}

		}
	}


	if (flag == 0)
	{
		res = min(res, q_time);
	}

	//cout << "BFS:"<< q_time << endl;
}


void DFS(int level, int idx)
{
	if (level == M)
	{
		memset(visited, 0, sizeof(visited));

		BFS();
		return;
	}

	for (int i = idx; i < v.size(); i++)
	{
		if (selected[i] == 1)
			continue;

		selected[i] = 1;
		can_Virus.push_back({ v[i].first,v[i].second });
		DFS(level + 1, i);
		selected[i] = 0;
		can_Virus.pop_back();
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
				v.push_back({ i,j });
		}
	}

	DFS(0, 0);

	if (res == 21e8)
	{


		cout << -1;
	}
	else if (res == -21e8)
		cout << 0;
	else
	{
		cout << res - 1;
	}

	return 0;

}