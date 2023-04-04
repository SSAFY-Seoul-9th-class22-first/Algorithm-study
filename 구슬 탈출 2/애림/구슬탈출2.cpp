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
int dx[] = {  0,1,0,-1 };
bool Rsuccess = false, Bsuccess = false;
int res = 21e8;

int inverse(int dir)
{
	if (dir == 0) return 2;
	if (dir == 1) return 3;
	if (dir == 2) return 0;
	if (dir == 3)return 1;
	return -1;
}

pos Rmove(int dir, pos t)
{
	pos tmp = t;
	while (1)
	{
		if (map[tmp.y][tmp.x] == '#')
		{
			tmp.y -= dy[dir];
			tmp.x -= dx[dir];
			break;
		}

		if (map[tmp.y][tmp.x] == 'O')
		{
			Rsuccess = true;
			break;
		}

		tmp.y += dy[dir];
		tmp.x += dx[dir];
	}
	return tmp;
}

pos Bmove(int dir, pos t)
{
	pos tmp = t;

	while (1)
	{
		if (map[tmp.y][tmp.x] == '#')
		{
			tmp.y -= dy[dir];
			tmp.x -= dx[dir];
			break;
		}
		if (map[tmp.y][tmp.x] == 'O')
		{
			Bsuccess = true;
			break;
		}

		tmp.y += dy[dir];
		tmp.x += dx[dir];
	}

	return tmp;
}


void DFS(pos R, pos B, int cnt, int dir)
{
	if (cnt >= res)
		return;
	if (cnt > 10)
		return;
	

	Rsuccess = false;
	Bsuccess = false;


	//빨간공 움직이기
	//pos  NR ={ R.y + dy[dir],R.x + dx[dir] };
	pos NR=Rmove(dir, R);

	//파란공 움직이기
	//pos NB = { B.y + dy[dir],B.x + dx[dir] };
	pos NB= Bmove(dir, B);


	if (Bsuccess==true)
		return;
	else
	{
		if (Rsuccess==true)
		{
			res = min(res, cnt);
			return;
		}
	}

	
	//충돌검사
	if (NR.y == NB.y && NR.x==NB.x)
	{
		if (abs(NR.y - R.y) +abs(NR.x - R.x) < abs(NB.y - B.y) +abs(NB.x - B.x))
		{
			NB.y -= dy[dir];
			NB.x -= dx[dir];
		}
		else
		{
			NR.y -= dy[dir];
			NR.x -= dx[dir];
		}
	}

	/*
	cout << "=================DIR "<< dir<<"====================\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == NR.y && j == NR.x)
				cout << 'R' << " ";
			else if (i == NB.y && j == NB.x)
				cout << 'B' << " ";
			else
				cout << map[i][j]<<" ";

		}
		cout << "\n";
	}
	*/
	//0 2 // 1 3
	for (int i = 0; i < 4; i++)
	{
		if (i == dir) continue;
		if (inverse(dir) == i) continue;
		
		DFS(NR, NB, cnt + 1, i);
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

	for (int i = 0; i < 4; i++)
	{
		
		//cout << "START DIR " << i << endl;
		DFS(red, blue, 1, i);
		
	}

	if (res == 21e8)
		cout << -1;
	else
		cout << res;
	return 0;
}
