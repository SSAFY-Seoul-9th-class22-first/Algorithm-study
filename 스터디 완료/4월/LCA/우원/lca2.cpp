#include <string>
#include <iostream>
#include <queue>
#include <cstring>
#include <set>
#include <algorithm>

#define dep first
#define val second

using namespace std;
using pii = pair<int, int>;
using ll = long long int;

int n, m;
int depths[100100];
int idx[100100];
int trip[2 * 100100];
pii tree[8 * 100100];
vector<int> adj[100100];

int tt;
// root = 1
void input() {
	cin >> n ;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

void dfs(int now, int p = -1) {
	idx[now] = tt;
	trip[tt++] = now;
	for (int nxt : adj[now]) if (nxt != p) {
		depths[nxt] = depths[now] + 1;
		dfs(nxt, now);
		trip[tt++] = now;
	}
}

pii init(int st, int ed, int node) {
	if (st == ed) return tree[node] = { depths[trip[st]],  trip[st] };
	int mid = (st + ed) / 2;
	pii leftnode = init(st, mid, node * 2);
	pii rightnode = init(mid + 1, ed, node * 2 + 1);
	return tree[node] = min(leftnode, rightnode);
}

pii calret(int st, int ed, int node, int left, int right) {
	if (left > ed || right < st)  return { 21e8, -1 };
	if (left <= st && ed <= right) return tree[node];
	int mid = (st + ed) / 2;
	pii leftnode = calret(st, mid, node * 2, left, right);
	pii rightnode = calret(mid + 1, ed, node * 2 + 1, left, right);
	return min(leftnode, rightnode);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	input();
	dfs(1);
	init(0, 2*n-1, 1);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		int aa = idx[a] <= idx[b] ? idx[a] : idx[b];
		int bb = idx[a] <= idx[b] ? idx[b] : idx[a];
		pii ret = calret(0, 2*n - 1, 1, aa, bb);
		cout << ret.val << "\n";
	}
	return 0;
}
