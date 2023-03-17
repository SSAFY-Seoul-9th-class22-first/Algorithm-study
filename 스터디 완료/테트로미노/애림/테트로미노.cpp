#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int ans = -21e8;
int sum = 0;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,1,-1 };
int visited[501][501];
int map[501][501];
int N, M;

vector <pair<int, int>> v;

void DFS(int level,int y,int x)
{
	if (level == 3)
	{
		ans = max(ans, sum);
		//cout << sum << endl;
		//왜 20이 나와 스버ㅓㄹ
		/*
		if (ans == 20)
		{
			for (int i = 0; i < v.size(); i++)
				cout << v[i].first << " " << v[i].second << endl;
		}
		*/
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny<0 || nx<0 || ny>=N || nx>=M)
			continue;
		if (visited[ny][nx] == 1)
			continue;

		v.push_back({ ny,nx });
		visited[ny][nx] = 1;
		sum += map[ny][nx];
		DFS(level + 1, ny, nx);
		visited[ny][nx] = 0;
		sum -= map[ny][nx];
		v.pop_back();
	}
}

void check(int y, int x)
{
	//ㅗ 

	for (int i = 0; i < 4; i++)
	{
		int sum = map[y][x];
		for (int j = 0; j < 4; j++)
		{
			if (i != j)
			{
				
				int ny = y + dy[j];
				int nx = x + dx[j];

				if (ny<0 || nx<0 || ny>=N || nx>=M)
					continue;
				sum += map[ny][nx];

			}
		}

		ans = max(sum, ans);
	}

}
int main()
{

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			v.push_back({ i,j });
			sum += map[i][j];
			visited[i][j] = 1;
			DFS(0, i, j);
			sum -= map[i][j];
			v.pop_back();
			visited[i][j] = 0;


			check(i, j);
		}
	}

	cout << ans;
	return 0;
}