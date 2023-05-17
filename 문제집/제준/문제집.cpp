#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int todo_cnt[32323];
int N, M;
vector<int> adj[32323];

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		todo_cnt[y]++;
		adj[x].push_back(y);
	}

	priority_queue<int, vector<int>, greater<>> q;
	for (int i = 1; i <= N; i++) {
		if (todo_cnt[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.top();
		cout << now << " ";
		q.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			int temp = adj[now][i];
			todo_cnt[temp]--;
			if (todo_cnt[temp] == 0) q.push(temp);
		}
	}
}