#include <string>
#include <iostream>
#include <queue>
#include <cstring>
#include <set>
#include <algorithm>

#define dp first
#define pr second

using namespace std;
using pii = pair<int, int>;
using ll = long long int;

int n, m;
int vst[50050];
pii parent[50050];
vector<int> adj[50050];


// root = 1
void input() {
	cin >> n ;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		parent[i + 1].dp = 21e8;
	}
	parent[n].dp = 21e8;
}

void dfs(int now, int prev, int depth) {
	depth = min(depth, parent[now].dp);
	parent[now] = {depth+1, prev };
	for (int i = 0; i < adj[now].size(); ++i) {
		int nxt = adj[now][i];
		if (vst[nxt]) continue;
		vst[nxt] = 1;
		dfs(nxt, now, depth + 1);
		vst[nxt] = 0;
	}
}

int lca(int a, int b) {
	int low = parent[a].dp <= parent[b].dp ? a : b;
	int deep = parent[a].dp <= parent[b].dp ? b : a;
	int lowDepth = parent[low].dp;
	int deepDepth = parent[deep].dp;
	while (deep != low) {
		if (deepDepth > lowDepth) {
			deep = parent[deep].pr;
			deepDepth--;
		}
		else {
			deep = parent[deep].pr;
			low = parent[low].pr;
		}
	}
	return low;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	vst[1] = 1;
	dfs(1, -1, 0);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
	return 0;
}
