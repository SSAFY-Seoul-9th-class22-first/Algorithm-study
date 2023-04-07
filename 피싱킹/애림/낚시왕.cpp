#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
1�ʵ���  �Ͼ�� ��

1. ���ÿ��� ���������� ��ĭ �̵�
2. ���ÿ��� �ִ� ���� �ִ� ��� �� ���� ���� ����� �� ��´�. �� ������ �����ǿ��� ���� �� �������.
3. �� �̵��Ѵ�
	�־��� �ӵ��� �̵��ϰ�, �������� ��踦 �Ѵ� ��� ������ �ݴ�� �ٲ۴�.

4. �� �̵��� ��ģ �Ŀ� ��ĭ�� �� �θ��� �̻� ������ 
ũ�Ⱑ ���� ū �� ������ �� ��� ��ƸԴ´�.


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
	//���� ������ ���� ������ ĭ����
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
		// ���ÿ��� �ִ� ���� �ִ� ����� ���� ���� ����� ��� ���
		int tr = 1;
		while (1)
		{
			int tc = c;
			if (tr > R)
				break;
			if (map[tr][tc].size() != 0)
			{
				res += map[tr][tc][0].z;
				//��� �������
				map[tr][tc].clear();
				break;
			}

			tr++;
		}
		
		cout << "=================������==" << c << "======================\n";
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
		
		//�̵��ϱ�.

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
					//�ӷ¸�ŭ �̵���Ű��
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
					//ù���� ���ֱ�.
					map[r][c].erase(map[r][c].begin());

				}

			}
		}

		//�Ծ����
		for (int r = 1; r <= R; r++)
		{
			for (int c = 1; c <= C; c++)
			{
				if (map[r][c].size() <2)
					continue;
				
				sort(map[r][c].begin(), map[r][c].end(), comp);

				Shark winner = map[r][c][0];
				//�ϴ�����!
				map[r][c].clear();
				//�뻧�� �ٽ� �־���
				map[r][c].push_back(winner);

			}
		}

		
		cout << "=================�̵��߰� ��� �ο�==" << c << "======================\n";
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
		
		// �̵� flag =0 ����
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