#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<set>

#define R first
#define C second
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
vector<int> adj[32020];
int vst[32020];
void input() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}
}

void dfs(int now) {
	vst[now] = 1;
	for (int i = 0; i < adj[now].size(); i++) {
		int nxt = adj[now][i];
		if (vst[nxt]) continue;
		dfs(nxt);
	}
	cout << now << " ";
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	input();
	for (int i = 1; i <= n; ++i) {
		if (vst[i]) continue;
		dfs(i);
	}

	return 0;
}
