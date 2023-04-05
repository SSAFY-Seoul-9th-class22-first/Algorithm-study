#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int map[21][21];
int copyMap[21][21];
int res = -21e8;


void move(int dir)
{
	queue <int>q;

	//상
	if (dir == 0)
	{
		for (int c = 0; c < N; c++)
		{
			//위에서부터 저장.
			for (int r = 0; r < N; r++)
			{
				if (map[r][c])
				{
					q.push(map[r][c]);
					map[r][c] = 0;
				}

			}
			int nr = 0;
			int data = 0;
			while (!q.empty())
			{
				int value = q.front();
				q.pop();

				if (map[nr][c] == 0)
				{
					map[nr][c] = value;
					
				}
				else if (map[nr][c] == value)
				{
					map[nr][c] *= 2;
					nr++;
				}
				else
				{
					nr++;
					map[nr][c] = value;
				}

			}
		}
	}
	//하
	else if (dir == 1)
	{
		for (int c = 0; c < N; c++)
		{
			//위에서부터 저장.
			for (int r = N-1; r >=0; r--)
			{
				if (map[r][c])
				{
					q.push(map[r][c]);
					map[r][c] = 0;
				}

			}
			int nr = N-1;
			int data = 0;
			while (!q.empty())
			{
				int value = q.front();
				q.pop();

				if (map[nr][c] == 0)
				{
					map[nr][c] = value;

				}
				else if (map[nr][c] == value)
				{
					map[nr][c] *= 2;
					nr--;
				}
				else
				{
					nr--;
					map[nr][c] = value;
				}

			}
		}
	}
	//좌
	else if (dir == 2)
	{
		for (int r = 0; r < N; r++)
		{
			//위에서부터 저장.
			for (int c = 0; c < N; c++)
			{
				if (map[r][c])
				{
					q.push(map[r][c]);
					map[r][c] = 0;
				}

			}
			int nc = 0;
			int data = 0;
			while (!q.empty())
			{
				int value = q.front();
				q.pop();

				if (map[r][nc] == 0)
				{
					map[r][nc] = value;

				}
				else if (map[r][nc] == value)
				{
					map[r][nc] *= 2;
					nc++;
				}
				else
				{
					nc++;
					map[r][nc] = value;
				}

			}
		}
	}
	//우
	else
	{
		for (int r = 0; r < N; r++)
		{
			//위에서부터 저장.
			for (int c = N-1; c >=0; c--)
			{
				if (map[r][c])
				{
					q.push(map[r][c]);
					map[r][c] = 0;
				}

			}
			int nc = N-1;
			int data = 0;
			while (!q.empty())
			{
				int value = q.front();
				q.pop();

				if (map[r][nc] == 0)
				{
					map[r][nc] = value;

				}
				else if (map[r][nc] == value)
				{
					map[r][nc] *= 2;
					nc--;
				}
				else
				{
					nc--;
					map[r][nc] = value;
				}

			}
		}

	}
}

void dfs(int cnt)
{
	if (cnt == 5)
	{
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				res = max(res, map[r][c]);
			}
		}
		return;
	}

	

	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			copyMap[r][c] = map[r][c];
		}
	}


	for (int dir= 0; dir < 4; dir++)
	{
		move(dir);
		//4방향
		dfs(cnt + 1);

		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				map[r][c] = copyMap[r][c];
			}
		}
	}
	
}

int main()
{	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}

	dfs(0);

	cout << res;
	return 0;
}