#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


/*
N*N ����, r�� c��

�� �ִ� ĭ ���� ������ ĭ�� ���� �ϳ� �����ִ�.
���� ��ȣ ������ ��ȣ�� �����ϴ� ĭ�� �ִ�? -> ���� ����
di(1,2,3,4)�������� si �Ÿ� ������ ��� ĭ�� �ִ� ������ �ı��Ѵ�.

�ĭ�� ��ȣ���� ��ȣ�� �ϳ� ���� ĭ�� ��ĭ�̸�, ������ ��ĭ���� �̵��ȴ�. �ݺ�

���� ���� -> 4�� �̻� �����ϴ� ������ ������.

���� -> ���� ���� -> ���� ��ȭ
*/

int N,M;

vector<int> linearMap;
int map[51][51];
vector<pair<int, int>> answer;
vector<pair<int, int>> magic;

int sy, sx;
int dy[] = { 0,1,0,-1 };
int dx[] = { -1,0,1,0 };

int my[] = { 0,-1,1,0,0 };
int mx[] = { 0,0,0,-1,1 };

void mapTolinear()
{
	int cnt = 2;
	int shY = sy, shX = sx;
	int dir = 0;
	for (int block = 1; block <= N - 1; block++) {
		if (block == N - 1)
			cnt = 3;
		for (int i = 0; i < cnt; i++)
		{
			for (int j = 0; j < block; j++)
			{
				shY += dy[dir];
				shX += dx[dir];
				if(map[shY][shX]!=0)
					linearMap.push_back(map[shY][shX]);
			}
			dir = (dir + 1) % 4;
		}
	}
}

void linearTomap()
{
	memset(map, 0, sizeof(map));
	int cnt = 2;
	int shY = sy, shX = sx;
	int dir = 0;
	
	for (int block = 1; block <= N - 1; block++) {
		if (block == N - 1)
			cnt = 3;
		for (int i = 0; i < cnt; i++)
		{
			for (int j = 0; j < block; j++)
			{
				if (linearMap.size() == 0)
					break;
				shY += dy[dir];
				shX += dx[dir];
				map[shY][shX] = linearMap.front();
				linearMap.erase(linearMap.begin());

			}
			dir = (dir + 1) % 4;
		}
	}
	linearMap.clear();
}

void eraseMap()
{
	int data = linearMap[0];
	int cnt = 0;
	for (int i = 1; i < linearMap.size(); i++)
	{
		if (data == linearMap[i])
		{
			cnt++;
		}

		if (data != linearMap[i])
		{
			if (cnt >=3)
			{
				for (int j = i - 1; j >= i - 1 - cnt; j--)
					linearMap[j] = 0;

				for (int k = 0; k < 3; k++)
				{
					if (answer[k].first == data)
					{
						answer[k].second += (cnt+1);
					}
				}
			}
			
			data = linearMap[i];
			cnt = 0;
		}

		else if (i == linearMap.size() - 1)
		{
			if (cnt >= 3)
			{
				for (int j = i; j >= i - cnt; j--)
					linearMap[j] = 0;

				for (int k = 0; k < 3; k++)
				{
					if (answer[k].first == data)
					{
						answer[k].second += (cnt + 1);
					}
				}
			}
		}
		
	}

	vector <int> tmp;

	for (int i = 0; i < linearMap.size(); i++)
	{
		if (linearMap[i] != 0)
			tmp.push_back(linearMap[i]);
	}

	linearMap.clear();
	for (int i = 0; i < tmp.size(); i++)
	{
		linearMap.push_back(tmp[i]);
	}

}

void remap()
{
	if (linearMap.size() == 0)
		return;
	int cnt = 1;
	int data = linearMap[0];
	vector<int> newLinear;
	for (int i = 1; i < linearMap.size(); i++)
	{
		
		if (data == linearMap[i])
			cnt++;
		if (data != linearMap[i])
		{
			

			newLinear.push_back(cnt);
			newLinear.push_back(data);
			
			
			if (newLinear.size() >= N * N)
				break;
			cnt = 1;
			data = linearMap[i];

			if (i == linearMap.size() - 1)
			{
				newLinear.push_back(cnt);
				newLinear.push_back(data);
			}
		}
	}

	linearMap.clear();

	for (int i = 0; i < newLinear.size(); i++)
	{
		linearMap.push_back(newLinear[i]);
	}
	
}

bool check()
{
	if (linearMap.size() == 0)
		return true;
	int data = linearMap[0];
	int cnt = 0;
	for (int i = 1; i < linearMap.size(); i++)
	{
		if (data == linearMap[i])
		{
			cnt++;
		}

		if (data != linearMap[i])
		{
			if (cnt >= 3)
			{
				return false;
			}
			data = linearMap[i];
			cnt = 0;
		}
	}
	if (cnt >= 3)
	{
		return false;
	}
	return true;
}

int main()
{
	cin >> N>>M;


	sy = (N + 1) / 2;
	sx = (N + 1) / 2;

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			cin >> map[r][c];

	for (int i = 0; i < M; i++)
	{
		int s, d;
		cin >> d >> s;
		magic.push_back({ d,s });
	}
	mapTolinear();
	if (linearMap.size() == 0)
	{
		cout << 0;
		return 0;
	}
	else
		linearTomap();
	answer.push_back({ 1, 0 });
	answer.push_back({ 2, 0 });
	answer.push_back({ 3, 0 });

	//
	for (int i = 0; i < M; i++)
	{
		//����
		int shY = sy, shX = sx;
		int dist = 0;
		int dir = magic[i].first;
		int s = magic[i].second;
		
		while (1)
		{
			if (shY<1 || shX<1 || shY>N || shX>N)
				break;
			if (dist == s)
				break;

			shY += my[dir];
			shX += mx[dir];

			map[shY][shX] = 0;
			dist++;

		}

		/*
		cout << "===========magic!!======================\n";
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				cout << map[i][j] << ' ';
			cout << "\n";
		}
		*/
		mapTolinear();
		
		linearTomap();
		/*
		cout << "===========magic!!======================\n";
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				cout << map[i][j] << ' ';
			cout << "\n";
		}
		*/
		mapTolinear();

		//�ߺ����� �������.
		while (!check())
		{
			eraseMap();
		}
		//
		//linearTomap();
		/*
		cout << "===========�ߺ����� �����!!======================\n";
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				cout << map[i][j] << ' ';
			cout << "\n";
		}
		*/
		//
		//mapTolinear();
		//map �籸��
		remap();
	
		
		linearTomap();
		/*
		cout << "===========���籸��!!======================\n";
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				cout << map[i][j] << ' ';
			cout << "\n";
		}
		*/
	}

	cout << 1 * answer[0].second + 2 * answer[1].second + 3 * answer[2].second;

	return 0;

}