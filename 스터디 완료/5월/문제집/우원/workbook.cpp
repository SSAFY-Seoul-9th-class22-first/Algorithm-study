#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
int cnt[32010];
vector<int> adj[32010];

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		cnt[b]++;
	}
}

void bfs()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; ++i){
		if (cnt[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int x = pq.top(); pq.pop();
		cout << x << " ";
		for (int i = 0; i < adj[x].size(); i++){
			int nxt = adj[x][i];
			cnt[nxt]--;
			if (cnt[nxt] == 0) pq.push(nxt);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	bfs();
	return 0;
}
