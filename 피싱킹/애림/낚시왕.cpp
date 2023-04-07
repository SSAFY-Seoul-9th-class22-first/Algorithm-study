#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
1초동안  일어나는 일

1. 낚시왕이 오른쪽으로 한칸 이동
2. 낚시왕이 있는 열에 있는 상어 중 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
3. 상어가 이동한다
	주어진 속도로 이동하고, 격자판의 경계를 넘는 경우 방향을 반대로 바꾼다.

4. 상어가 이동을 마친 후에 한칸에 상어가 두마리 이상 있으면 
크기가 가장 큰 상어가 나머지 상어를 모두 잡아먹는다.


*/
typedef struct {
	int  s, d, z, m;
}Shark;

typedef struct {
	int y, x;
}pos;

int R, C, M;
vector <Shark> sharkInfo;
vector <Shark> map[101][101];
pos man;

int dy[] = { 0,-1,1,0,0 };
int dx[] = { 0,0,0,1,-1 };

int backDir[] = { 0,2,1,4,3 };

bool comp(Shark a, Shark b)
{
	if (a.z> b.z)
		return true;
	if (a.z < b.z)
		return false;
	return false;
}
int main()
{
	cin >> R >> C >> M;

	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		//sharkInfo.push_back({ r,c,s,d,z });
		if (d == 1 || d == 2)
		{
			s = s % (2 * (R - 1));
		}
		else
			s = s % (2 * (C - 1));
		map[r][c].push_back({ s,d,z,0 });
	}

	int c = 0;
	int res = 0;
	//가장 오른쪽 열의 오른쪽 칸까지
	while (c <=C)
	{
		
		c++;
		/*
		cout << "===================" << c << "======================\n";
		for (int r = 1; r <= R; r++)
		{
			for (int c = 1; c <= C; c++)
			{
				if (map[r][c].size() == 0)
					cout << "." << " ";
				else
					cout << "S" << " ";
			}
			cout << "\n";
		}
		*/
		// 낚시왕이 있는 열에 있는 상어중 땅과 제일 가까운 상어 잡기
		int tr = 1;
		while (1)
		{
			int tc = c;
			if (tr > R)
				break;
			if (map[tr][tc].size() != 0)
			{
				res += map[tr][tc][0].z;
				//상어 사라지기
				map[tr][tc].clear();
				break;
			}

			tr++;
		}
		
		cout << "=================잡혔음==" << c << "======================\n";
		for (int r = 1; r <= R; r++)
		{
			for (int c = 1; c <= C; c++)
			{
				if (map[r][c].size() == 0)
					cout << "." << " ";
				else
					cout << "S" << " ";
			}
			cout << "\n";
		}
		
		//이동하기.

		for (int r = 1; r <= R; r++)
		{
			for (int c = 1; c <= C; c++)
			{
				if (map[r][c].size() == 0)
					continue;
				if (map[r][c][0].m == 0)
				{
					
					int nr = r;
					int nc = c;
					int cnt = 0;
					int dir = map[r][c][0].d;
					//속력만큼 이동시키기
					while (cnt < map[r][c][0].s)
					{
						nr += dy[dir];
						nc += dx[dir];

						if (dir == 1)
						{
							if (nr == 0)
							{
								dir = backDir[dir];
								nr = 2;
							}
						}
						else if (dir == 2)
						{
							if (nr > R)
							{
								dir = backDir[dir];
								nr = R - 1;
							}
						}
						else if (dir == 3)
						{
							if (nc > C)
							{
								dir = backDir[dir];
								nc = C - 1;
							}
						}
						else
							if (nc ==0)
							{
								dir = backDir[dir];
								nc = 2;
							}
				
						cnt++;

					}

					map[nr][nc].push_back({ map[r][c][0].s,dir,map[r][c][0].z,1});
					//첫원소 없애기.
					map[r][c].erase(map[r][c].begin());

				}

			}
		}

		//먹어야해
		for (int r = 1; r <= R; r++)
		{
			for (int c = 1; c <= C; c++)
			{
				if (map[r][c].size() <2)
					continue;
				
				sort(map[r][c].begin(), map[r][c].end(), comp);

				Shark winner = map[r][c][0];
				//싹다지워!
				map[r][c].clear();
				//대빵만 다시 넣어줌
				map[r][c].push_back(winner);

			}
		}

		
		cout << "=================이동했고 상어 싸움==" << c << "======================\n";
		for (int r = 1; r <= R; r++)
		{
			for (int c = 1; c <= C; c++)
			{
				if (map[r][c].size() == 0)
					cout << "." << " ";
				else
					cout << "S" << map[r][c][0].d<<" ";
			}
			cout << "\n";
		}
		
		// 이동 flag =0 셋팅
		for (int r = 1; r <= R; r++)
		{
			for (int c = 1; c <= C; c++)
			{
				if (map[r][c].size() ==0)
					continue;

				map[r][c][0].m = 0;
			}
		}

		

	}

	
	

	cout << res;
	return 0;

}