#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
N*N (1~N)

봄 - 자신 나이만큼 양분먹고 나이 1 증가
	- 나이가 어린 나무부터 양분 먹고
	- 양분이 부족해 자기 나이만큼 못먹은 나무는 죽는다.

여름 - 봄에 죽은 나무 /2 가 양분이됨
가을 - 나무 나이가 5의 배수이면 인접한 8개칸에 1인 나무 생성
겨울 - S2D2가 양분 추가한다. 추가되는 양분양은 A[r][c]

*/

struct Tree {
	int y, x, age;
};

int N, M, K;
int A[11][11];
int map[11][11];

vector <Tree>t[11][11];
vector <Tree>dead;

int dy[] = { -1,0,1,-1,1,-1,0,1 };
int dx[] = { -1,-1,-1,0,0,1,1,1 };

bool compare(Tree a, Tree b)
{
	if (a.age >b.age)
		return true;
	if (a.age < b.age)
		return false;
	return false;
}

void springSummer()
{
	//봄 - 자신 나이만큼 양분먹고 나이 1 증가
	// - 나이가 어린 나무부터 양분 먹고
	// - 양분이 부족해 자기 나이만큼 못먹은 나무는 죽는다.

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			
			int flag = 0;
			int deadidx = 0;
			int tSize = t[i][j].size();

			for (int k = tSize - 1; k >= 0; k--)
			{
				if (map[i][j] < t[i][j][k].age)
				{
					deadidx = k;
					flag = 1;
					break;
				}
				map[i][j] -= t[i][j][k].age;
				t[i][j][k].age += 1;
			}

			if (flag == 1)
			{
				while (deadidx>=0)
				{
					map[i][j] += t[i][j][deadidx].age / 2;
					t[i][j].erase(t[i][j].begin() + deadidx);
					deadidx--;
				}
			}
		}
	}
}

void fall()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int tSize = t[i][j].size();

			for (int k = 0; k < tSize; k++)
			{
				if (t[i][j][k].age % 5 != 0)
					continue;

				for (int i2 = 0; i2 < 8; i2++)
				{
					int ny = i + dy[i2];
					int nx = j + dx[i2];

					if (ny<1 || nx<1 || ny>N || nx>N)
						continue;

					t[ny][nx].push_back({ ny,nx,1 });
				}
			}
		}
	}
}

void winter()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			map[i][j] += A[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	//처음엔 양분 모두 5
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			map[i][j] = 5;
		}
	}

	//A 세팅
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];

	//나이세팅
	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;

		t[x][y].push_back({ x,y,z });
	}

	for (int k = 0; k < K; k++)
	{
		//cout << k;
		springSummer();
		fall();
		winter();
	}

	int res = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			res += t[i][j].size();
		}
	}

	cout << res;
}

