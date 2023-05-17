#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
N개의 문제 모두 풀어야함
먼저 푸는 것이 좋은 문제가 있는 문제는 먼저 풀어야하는 문제 먼저 풀어야함
가능한 쉬운난이도부터

*/

int N,M;
vector <int> v[32001];
int visited[32001];
int degree[32001];

void topology()
{
	priority_queue <int, vector<int>, greater<int>> q;

	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
		{
			visited[i] = 1;
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int now = q.top();
		q.pop();

		for (auto a : v[now])
		{
			if (visited[a] == 1)
				continue;
			degree[a]--;
			if (degree[a] == 0)
			{
				visited[a] = 1;
				q.push(a);
			}
		}
		cout << now << " ";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		degree[i] = 0;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		degree[b]++;
	}
	topology();
	return 0;
}