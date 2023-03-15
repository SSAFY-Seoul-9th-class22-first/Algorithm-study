#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct coord {
	int y, x;
};

int N, M;
int map[9][9], map2[9][9];
int level = 3;
int ans = -21e8;
int visited[9][9];
void BFS()
{
	int dy[] = { -1,1,0,0 };
	int dx[] = { 0,0,-1,1 };

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map2[i][j] = map[i][j];

	queue<coord> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map2[i][j] == 2)
			{
				q.push({ i, j });
				visited[i][j] = 1;

				while (!q.empty())
				{
					coord cur = q.front();
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int ny = cur.y + dy[k];
						int nx = cur.x + dx[k];
						if (ny < 0 || nx < 0 || ny >= N || nx >= M)
							continue;
						if (visited[ny][nx] == 1) continue;
						if (map2[ny][nx] != 0)
							continue;

						visited[ny][nx] = 1;
						map2[ny][nx] = 2;
						q.push({ ny,nx });
					}
				}

			}

		}
	}

	int cnt = 0;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (map2[i][j] == 0)
				cnt++;
		}

	ans = max(ans, cnt);
}

void DFS()
{
	if (level == 0)
	{
		return BFS();
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] != 0)
				continue;

			map[i][j] = 1;
			level--;
			DFS();
			level++;
			map[i][j] = 0;
		}
	}

}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}

	DFS();
	cout << ans << endl;

	return 0;
}