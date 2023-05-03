#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[32323];
int visited[32323];

void dfs(int node) {
	if (visited[node] == 1) return;
	for (int i : v[node]) {
		if (visited[i] == 0) {
			dfs(i);
		}
	}
	visited[node] = 1;
	cout << node << " ";
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i{}; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (v[i].empty()) {
			visited[i] = 1;
			cout << i << " ";
		}
		else q.push(i);
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (visited[now] == 0) dfs(now);
	}

	return 0;
}