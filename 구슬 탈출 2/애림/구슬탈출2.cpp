#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pos {
	int y, x;
};
int N, M;
char map[11][11];
pos blue, red, goal;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
bool Rsuccess = false, Bsuccess = false;
int res = -21e8;

int inverse(int dir)
{
	if (dir == 0) return 2;
	if (dir == 1) return 3;
	if (dir == 2) return 0;
	if (dir == 3)return 1;
	return -1;
}

pos Rmove(int dir, pos t, pos B)
{
	pos tmp = t;
	while (1)
	{
		if (map[t.y][t.x] == '#')
		{
			t.y -= dy[dir];
			t.x -= dx[dir];
			break;
		}
		if (map[t.y][t.x] == 'O')
		{
			Rsuccess = true;
			break;
		}
	
		if (t.y == B.y && t.x == B.x)
		{
			t.y -= dy[dir];
			t.x -= dx[dir];
			break;
		}
		t.y += dy[dir];
		t.x += dx[dir];

	}
	return t;
}
pos Bmove(int dir, pos t,pos R)
{
	pos tmp = t;
	while (1)
	{
		if (map[t.y][t.x] == '#')
		{
			t.y -= dy[dir];
			t.x -= dx[dir];
			break;
		}
		if (map[t.y][t.x] == 'O')
		{
			Bsuccess = true;
			break;
		}
		if (t.y==R.y && t.x==R.x)
		{
			t.y -= dy[dir];
			t.x -= dx[dir];
			break;
		}
		t.y += dy[dir];
		t.x += dx[dir];

	}
	return t;
}


void DFS(pos R, pos B, int cnt, int dir)
{
	if (cnt >= 10)
		return;

	if (Bsuccess == true && Rsuccess == true)
	{
		return;
	}

	else if (Bsuccess == true)
		return;
	else if (Rsuccess == true)
	{
		res = max(res, cnt);
		return;
	}
	//빨간공 움직이기
	R = Rmove(dir, R,B);

	//파란공 움직이기
	B = Bmove(dir, B,R);

	//0 2 // 1 3
	for (int i = 0; i < 4; i++)
	{
		if (i == dir) continue;
		if (inverse(dir) == i) continue;
		DFS(R, B, cnt + 1, i);
	}

}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'B')
			{
				blue = { i,j };
				map[i][j] = '.';
			}
			else if (map[i][j] == 'R')
			{
				red = { i,j };
				map[i][j] = '.';
			}
			else if (map[i][j] == 'O')
				goal = { i,j };
		}
	}

	DFS(red, blue, 1, 0);
	cout << res;
	return 0;
}
