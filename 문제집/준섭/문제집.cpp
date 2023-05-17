#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[32323];
int check[32323];
int visited[32323];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {

	int n, m;
	cin >> n >> m;

	for (int i{}; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		check[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int now = pq.top();
		cout << now << " ";
		pq.pop();
		visited[now] = 1;

		if (v[now].size() == 0) continue;

		for (int i{}; i < v[now].size(); i++) {
			check[v[now][i]]--;
			if (check[v[now][i]] == 0) { 
				
				pq.push(v[now][i]); 
			}
		}
	}
	return 0;
}