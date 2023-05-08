#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
vector <vector<int>> v;
vector <int> degree,result;
queue <int> q;

void topology()
{
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
			q.push(i);
	}

	for (int i = 1; i <= N; i++)
	{
		if (q.empty()) //
			return;

		int now = q.front();
		result.push_back(now);
		q.pop();

		for (int i = 0; i < v[now].size(); i++)
		{
			if (--degree[v[now][i]]==0)
				q.push(v[now][i]);
		}
	}
}
int main()
{
	
	int a, b;
	cin >> N >> M;
	v.assign(N + 1, vector <int>(0, 0));
	degree.assign(N + 1, 0);
	//result.assign(N + 1, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		degree[b]++;
	}

	topology();
	for (int i = 0; i < N; i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}