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
int ans = 0;
int cnt = 0;
int dir_left[] = { 3,0,1,2 };
int dir_back[] = { 2,3,0,1 };
void solve(int sy,int sx,int dir,int ans)
{

	for (int i = 0; i < 4; i++)
	{

		int ny = sy + dy[i];
		int nx = sx + dx[i];
		
		//다음칸이 이동못함.
		if (map[ny][nx] == 1  || ny<0 || nx<0 || ny>=N || nx>=M)
		{
			continue;
		}

		
		int ndir = dir_left[dir];
		int by = sy + dy[dir_left[dir]];
		int bx = sx + dx[dir_left[dir]];
		if (visited[by][bx] == 0 && map[by][bx] == 0)
		{
			visited[by][bx] = 1;
			solve(by, bx, ndir, ans + 1);
			
		}

	}

	//4방향 다 안될때
	int by2 = sy + dy[dir_back[dir]];
	int bx2 = sx + dx[dir_back[dir]];
	if (map[by2][bx2] == 1 || (by2<0 ||bx2<0 || by2>=N || bx2>=M))//후진 불가능
	{
		return;
	}
	else
	{
		
		//후진
		solve(by2, bx2, dir_back[dir],ans);
		
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
	solve(sy, sx, dir,ans);
	


	cout << ans << endl;
	return 0;

}