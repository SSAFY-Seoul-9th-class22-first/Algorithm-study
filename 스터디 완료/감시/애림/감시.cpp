#include <iostream>
#include <vector>
using namespace std;

int N, M;
int map[10][10];
int cpy[10][10];
vector <pair<int, int>> cctv_pos;
int result = 21e8;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
void check(int cctv_num, int sy, int sx, int dir)
{
	int ny = sy, nx = sx;
	while (1)
	{
		ny += dy[dir];
		nx += dx[dir];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == 6)
			break;

		if (map[ny][nx] == 0)
			map[ny][nx] = -1;

	}
}


void dfs(int cctv_idx)
{

	if (cctv_idx == cctv_pos.size())
	{
		//cout << cctv_idx << endl;
		int cnt = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				//아무것도 변한게없음
				cout << map[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "----------------------------------" << endl;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				//아무것도 변한게없음
				if (map[i][j] == 0)
				{
					cnt++;
				}
			}

		//cout << cnt << endl;;
		result = min(result, cnt);
		return;
	}

	memset(cpy, 0, sizeof(cpy));
	int cctv_num = map[cctv_pos[cctv_idx].first][cctv_pos[cctv_idx].second];

	cout << cctv_idx << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//아무것도 변한게없음
			cout << map[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "----------------------------------" << endl;
	if (cctv_num == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			memcpy(&cpy, &map, sizeof(map));
			check(cctv_num, cctv_pos[cctv_idx].first, cctv_pos[cctv_idx].second, i);
			dfs(cctv_idx + 1);
			memcpy(&map, &cpy, sizeof(cpy));

		}

	}

	if (cctv_num == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			memcpy(&cpy, &map, sizeof(map));
			check(cctv_num, cctv_pos[cctv_idx].first, cctv_pos[cctv_idx].second, i);
			check(cctv_num, cctv_pos[cctv_idx].first, cctv_pos[cctv_idx].second, i + 2);
			dfs(cctv_idx + 1);
			memcpy(&map, &cpy, sizeof(map));

		}

	}
	if (cctv_num == 3)
	{
		for (int i = 0; i < 4; i++)
		{
			memcpy(&cpy, &map, sizeof(map));
			check(cctv_num, cctv_pos[cctv_idx].first, cctv_pos[cctv_idx].second, i);
			check(cctv_num, cctv_pos[cctv_idx].first, cctv_pos[cctv_idx].second, (i + 1) % 4);
			dfs(cctv_idx + 1);
			memcpy(&map, &cpy, sizeof(map));

		}

	}
	if (cctv_num == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			memcpy(&cpy, &map, sizeof(map));
			check(cctv_num, cctv_pos[cctv_idx].first, cctv_pos[cctv_idx].second, (i) % 4);
			check(cctv_num, cctv_pos[cctv_idx].first, cctv_pos[cctv_idx].second, (i + 1) % 4);
			check(cctv_num, cctv_pos[cctv_idx].first, cctv_pos[cctv_idx].second, (i + 2) % 4);
			dfs(cctv_idx + 1);
			memcpy(&map, &cpy, sizeof(cpy));

		}

	}

	if (cctv_num == 5)
	{

		memcpy(&cpy, &map, sizeof(map));
		check(cctv_num, cctv_pos[cctv_idx].first, cctv_pos[cctv_idx].second, 0);
		check(cctv_num, cctv_pos[cctv_idx].first, cctv_pos[cctv_idx].second, 1);
		check(cctv_num, cctv_pos[cctv_idx].first, cctv_pos[cctv_idx].second, 2);
		check(cctv_num, cctv_pos[cctv_idx].first, cctv_pos[cctv_idx].second, 3);
		dfs(cctv_idx + 1);
		memcpy(&map, &cpy, sizeof(cpy));


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
			if (map[i][j] >= 1 && map[i][j] <= 5)
				cctv_pos.push_back({ i,j });
		}
	}

	dfs(0);

	cout << result;
}