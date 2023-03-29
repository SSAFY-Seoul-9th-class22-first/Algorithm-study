#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
* 
n*N�� �� 
�л��� N^2

1<= <=N
���л��� �����Ѵ� �л� 4�� ��Ģ�� �̿��� �ڸ� ���ϱ�. 
������ ��ĭ ���� 

����ִ� ĭ�߿� �����ϴ� �л��� ������ ĭ�� ���� ���� ĭ���� �ڸ� ���ϱ�.
��������? -> ����ִ� ĭ�� ���� ���� ĭ.
�� ������? ���ǹ�ȣ�� ���� ����ĭ. �̰͵� �������� ���� ��ȣ�� ���� ���� ĭ

�����ϴ� ��� �迭
1�� ���� �����ϴ� ĭ�� ����
2������ �����ϴ� ĭ�� ����
������ ��ĭ���� 
3������ -> ����

*/
struct node {

	int y, x;
	int cnt;
	int space;
};

int N;
int map[21][21];
int visited[21][21];
vector <int> like_num[5000];
int res;
vector<node> like;
vector<node> noPerson;
queue <node> noPerson_q;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int max_count;

bool compare(node a, node b)
{
	if (a.y < b.y)
		return true;
	if (a.y > b.y)
		return false;
	if (a.x < b.x)
		return true;
	if (a.x > b.x)
		return false;
}
bool check(int idx,int y,int x)
{
	for (int i = 0; i < 4; i++)
	{
		if (map[y][x] == like_num[idx][1 + i])
			return true;
	}
	return false;
}

int check2(int idx)
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] != like_num[idx][0])
				continue;
			for (int l = 0; l < 4; l++)
			{
				int ny = i + dy[l];
				int nx = j + dx[l];

				if (ny<1 || nx<1 || ny>N || nx>N)
					continue;

				for (int k = 0; k < 4; k++) {
					if (map[ny][nx] == like_num[idx][1 + k])
						cnt++;
				}
			}
		}
	}

	return cnt;
}

int find_LikeSpace(int idx)
{
	int IDX = like_num[idx][0];
	int max = -21e8;
	max_count = 0;
	int spaceCnt = 0;
	for (int i = 1; i <= N ; i++)
	{
		for (int j = 1; j <= N ; j++)
		{
			if (map[i][j] != 0)
				continue;
			int cnt = 0;
			spaceCnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (ny < 1 || nx < 1 || ny >N || nx >N)
					continue;
				
				if (check(idx,ny,nx))
					cnt++;
				if (map[ny][nx] == 0)
					spaceCnt++;
			}

			if (max <= cnt)
			{
				//if (max == cnt)
				
				if (max!=-21e8 && max != cnt)
					like.clear();

				max = cnt;

				like.push_back({ i,j,cnt,spaceCnt });
				
			}
		}
	}

	if (like.size() != 1)
		return -1;
	else
		return like.size() - 1;

}

int max_space()
{
	int res;
	int cnt = 0;
	int max = -21e8;
	for (int i =0;i<like.size();i++)
	{
		if (like[i].space >= max)
		{
			if (max!=-21e8 && like[i].space != max)
				noPerson.clear();
		
			res = i;
			max = like[i].space;
			noPerson.push_back({ like[i].y,like[i].x,like[i].cnt,like[i].space });
		}
	}

	if (noPerson.size() != 1)
		return -1;
	else
		return res;
}
int main()
{
	cin >> N;
	for (int i = 1; i <= N * N; i++)
	{
		int n, a1, a2, a3, a4;
		cin >> n >> a1 >> a2 >> a3 >> a4;
		like_num[i].push_back(n);
		like_num[i].push_back(a1);
		like_num[i].push_back(a2);
		like_num[i].push_back(a3);
		like_num[i].push_back(a4);
	}


	for (int i = 1; i <= N*N; i++)
	{
		if (find_LikeSpace(i) == -1)
		{
			int max_res = max_space();
			if (max_res == -1)
			{
				//3�� �켱����
				sort(noPerson.begin(), noPerson.end(), compare);
				map[noPerson[0].y][noPerson[0].x] = like_num[i][0];
				visited[noPerson[0].y][noPerson[0].x] = like_num[i][0];
			}
			else
			{
				map[like[max_res].y][like[max_res].x] = like_num[i][0];
				visited[like[max_res].y][like[max_res].x] = like_num[i][0];
			}
		}

		else
		{
			map[like[like.size() - 1].y][like[like.size() - 1].x] = like_num[i][0];
			visited[like[like.size() - 1].y][like[like.size() - 1].x] = like_num[i][0];
		}

		/*
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "---------------------\n";
		*/
		noPerson.clear();
		like.clear();
	}

	/*
	for (int i = 1; i <= N ; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	for (int i = 1; i <= N*N; i++)
	{
		int k = check2(i);
		//cout << k << endl;
		if (k == 0)
			res += 0;
		else if (k == 1)
			res += 1;
		else if (k == 2)
			res += 10;
		else if (k == 3)
			res += 100;
		else if (k == 4)
			res += 1000;
	}


	cout << res;

	return 0;
}