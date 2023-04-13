#include <iostream>
#include <vector>
using namespace std;

int N, M;
int map[51][51];
int visited[51][51];

int sx, sy, dir;
int ny, nx;
//0 북 1 동 2 남 3 서
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int result = -21e8;
int dir_left[] = { 3,0,1,2 };
int dir_back[] = { 2,3,0,1 };
void solve(int sy, int sx, int dir, int ans)
{

	for (int i = 0; i < 4; i++)
	{
		int ndir = (dir+3-i)%4;
		int by = sy + dy[ndir];
		int bx = sx + dx[ndir];

		//다음칸이 이동못함.
		if (map[by][bx] == 1 || by < 0 || bx < 0 || by >= N || bx >= M)
		{
			continue;
		}


		
		if (visited[by][bx] == 0 && map[by][bx] == 0)
		{
			visited[by][bx] = 1;
			solve(by, bx, ndir, ans + 1);
		//	visited[by][bx] = 0;

		}

	}

	//4방향 다 안될때
	int by2 = sy + dy[dir_back[dir]];
	int bx2 = sx + dx[dir_back[dir]];
	
	if (map[by2][bx2] == 1 || by2 < 0 || bx2 < 0 || by2 >= N || bx2 >= M)//후진 불가능
	{
		result = max(ans, result);
		return;
	}
	
	else
	{
		solve(by2, bx2, dir, ans);
	}

}

int main()
{
	cin >> N >> M;
	cin >> sy >> sx >> dir;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}

	visited[sy][sx] = 1;
	solve(sy, sx, dir, 1);



	cout << result << endl;
	return 0;

}
