#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

typedef struct {
	int r, c,destroy;
	int day;
}pos;

int N, M,k;
int map[1001][1001];
string strmap[1001];
vector <pos> v;
int visited[1001][1001][11];
int res[1001][1001];
int cant;

int BFS(int r, int c)
{
	queue <pos> q;
	q.push({ r,c ,0,0 });

	int dy[] = { -1,0,1,0 };
	int dx[] = { 0,1,0,-1 };

	visited[r][c][0] = visited[r][c][1] = 1;
	res[r][c] = 1;
	while (!q.empty())
	{
		pos now = q.front();
		q.pop();
		if (now.r == N && now.c== M)
			return res[N][M];

		for (int i = 0; i < 4; i++)
		{
			int ny = now.r + dy[i];
			int nx = now.c + dx[i];

			if (ny<1 || nx<1 || ny>N || nx>M)
				continue;
			if (map[ny][nx] == 0)
			{

				if (visited[ny][nx][now.destroy] == 0)
				{
					visited[ny][nx][now.destroy] = 1;
					res[ny][nx] = res[now.r][now.c] + 1;
					q.push({ ny,nx,now.destroy ,(now.day + 1) % 2 });

				}
			}
			else
			{
				//π„¿Ã∏È?
				if (now.day == 1)
				{
					res[now.r][now.c] += 1;
					q.push({ now.r,now.c,now.destroy,(now.day + 1) % 2 });
				}
				else
				{
					if (now.day == 0 && now.destroy == 0 && map[ny][nx] == 1 && visited[ny][nx][now.destroy + 1] == 0)
					{
						visited[ny][nx][now.destroy + 1] = 1;
						res[ny][nx] = res[now.r][now.c] + 1;

						q.push({ ny,nx,now.destroy + 1 ,(now.day + 1) % 2 });

					}

					else if (now.day == 0 && now.destroy < k && map[ny][nx] == 1 && visited[ny][nx][now.destroy + 1] == 0)
					{
						visited[ny][nx][now.destroy + 1] = 1;
						res[ny][nx] = res[now.r][now.c] + 1;
						q.push({ ny,nx,now.destroy + 1 ,(now.day + 1) % 2 });
					}
				}


			}
			if (ny == N && nx == M)
				return res[N][M];
		}
	}
	

	
	return -1;
}


int main()
{
	cin >> N >> M>>k;

	for (int i = 1; i <= N; i++)
	{
		cin >> strmap[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (strmap[i][j] == '0')
				map[i][j+1] = 0;
			else
			{
				map[i][j+1] = 1;
			}
		}
	}

	cout << BFS(1, 1);
	return 0;
}

