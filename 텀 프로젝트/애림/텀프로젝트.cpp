#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T;
int N;
vector <int> parent;
vector <int> visited;
vector <int> v;

int dfs(int idx, int first)
{
	if (visited[idx] == 1)
	{

		for (int i = 1; i < v.size(); i++)
		{
			visited[v[i]] = 0;
		}

		return -1;
	}
	v.push_back(idx);
	visited[idx] = 1;


	if (parent[idx] == first)
	{
		return v.size();
	}

	return dfs(parent[idx], first);

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		parent.assign(N + 1, 0);
		visited.assign(N + 1, 0);
		for (int i = 1; i <= N; i++)
		{
			cin >> parent[i];
		}

		int ans = 0;
		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == 1)
				continue;
			int d = dfs(i, i);
			v.clear();
			//cout <<i <<":" << d << "\n";
			if (d == -1)
				continue;
			ans += d;

		}

		cout << N - ans << "\n";


	}
	return 0;
}
