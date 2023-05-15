#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue <char> q;

int R, C;
string arr[21];
int visited[30];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int ans = -21e8;

void DFS(int y, int x, int cnt)
{
	ans = max(ans, cnt);

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny<0 || nx<0 || ny>=R  || nx>=C)
			continue;

		if (visited[arr[ny][nx]-'A'] == 1)
			continue;

		visited[arr[ny][nx]-'A'] = 1;
		DFS(ny, nx, cnt + 1);
		visited[arr[ny][nx]-'A'] = 0;
	}
}

int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		cin >> arr[i];
	}

	visited[arr[0][0] - 'A'] = 1;
	DFS(0, 0, 1);

	cout << ans;

	return 0;
}