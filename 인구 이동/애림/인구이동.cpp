#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, L, R;
int map[51][51];
int day = 1; 
int visited[51][51] ;
int sum = 0;
vector <pair<int, int>> v;
/*
L이상 R이하면 두 국가간 인구 이동
연합국 각칸의 값은 평균.
연합 해체하고 다시 루프돌기
인구이동이 불가능할때까지 돈다.
*/
void BFS(int y,int x)
{
	int dy[] = { -1,0,1,0 };
	int dx[] = { 0,1,0,-1 };

	queue <pair<int, int>> q;
	
	q.push({ y,x });
	if(visited[y][x]==0)
		v.push_back({ y,x });
	visited[y][x] = 1;
		
	int cnt=1;
	
	while (!q.empty())
	{
		int sy = q.front().first;
		int sx = q.front().second;
		
		q.pop();
		sum += map[sy][sx];
		for (int i = 0; i < 4; i++)
		{
			int ny = sy + dy[i];
			int nx = sx + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (visited[ny][nx] == 1)
				continue;
			if (abs(map[sy][sx] - map[ny][nx]) >= L && abs(map[sy][sx] - map[ny][nx]) <= R)
			{
				visited[ny][nx] = 1;
				q.push({ ny,nx });
				
				v.push_back({ ny,nx });
		
				
			}
		}
	}
	
	sum /= v.size();
	for (int i = 0; i < v.size(); i++)
	{
		map[v[i].first][v[i].second] = sum;
	}
	v.clear();
	sum = 0;
	
	//cout << "sssss"<<v.size() << " " << sum << endl;
	

}
bool cantBFS(int y,int x)
{
	int dy[] = { -1,0,1,0 };
	int dx[] = { 0,1,0,-1 };
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (visited[ny][nx] == 1)
			continue;
		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
			continue;
		if (abs(map[y][x] - map[ny][nx]) >= L && abs(map[y][x] - map[ny][nx]) <= R)
		{
			cnt++;
		}
	}
	if (cnt == 0) return false;
	else return true;
}
/*
void print_map()
{
	//cout << "-----------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << map[i][j] << "\t";
		cout << endl;
	}
}
*/
int main()
{
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	
	int date = 0;
	int cnt_com = 0;
	
	while (1)
	{
		//print_map();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				
				if (visited[i][j] == 1)
					continue;
				
				if (!cantBFS(i, j)) {

					cnt_com++;
				}
				else
				{
					BFS(i, j);


				}
			}
		}

		if (cnt_com == N * N)
			break;
		else
		{
			//cout << v.size() <<" "<<sum << endl;
			
			
			date++;
		}
		cnt_com = 0;
		memset(visited, 0, sizeof(visited));
		
	}

	cout << date;

	return 0;
}