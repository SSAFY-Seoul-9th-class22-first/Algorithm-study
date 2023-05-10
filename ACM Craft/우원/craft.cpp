#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>

#define R first
#define C second
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n, k;
int costs[1010];
int memo[1010];
vector<int> adj[1010];
int target;
void input() {
	cin >> n >> k;
	memset(memo, -1, sizeof(memo));
	for (int i = 1; i <= n; ++i) {
		cin >> costs[i];
		adj[i].clear();
	}
	for (int i = 0; i < k; ++i) {
		int x, y; cin >> x >> y;
		adj[y].push_back(x);
	}
	cin >> target;
}

int dfs(int now) {
	if (memo[now] != -1) return memo[now];
	int mx = 0;
	for (int i = 0; i < adj[now].size(); ++i) {
		int nxt = adj[now][i];
		int tmp = dfs(nxt) ;
		mx = max(tmp, mx);
	}
	return memo[now] = mx + costs[now];
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		input();
		int ret = dfs(target);
		cout << ret << "\n";
	}
	return 0;
}
