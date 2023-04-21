#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct
{
	int next;
	int w;
}node;

vector <node> v[10000];
int maxlen = -21e8;
int maxnode;
int visited[10001];
void dfs(int curIdx, int maxw)
{
	if (visited[curIdx] == 1)
		return;

	if (maxlen <maxw)
	{
		maxnode = curIdx;
		maxlen = maxw;
	}
	visited[curIdx] = 1;
	for (int i = 0; i < v[curIdx].size(); i++)
	{
		node cur = v[curIdx][i];
	//	maxw += cur.w;
		dfs(cur.next, maxw+cur.w);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int p, c, w;
		cin >> p >> c >> w;
		v[p].push_back({ c,w });
		v[c].push_back({ p,w });
	}
	dfs(1, 0);

	maxlen = 0;
	memset(visited, 0, sizeof(visited));

	dfs(maxnode,0);
	cout << maxlen;
	return 0;
}