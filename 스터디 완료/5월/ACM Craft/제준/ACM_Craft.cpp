#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int T;
int N, K;
int W;
int times[1010];
int dp_times[1010];
vector<int> adj[1010];
int todo_count[1010];

int main() {
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> times[i];
		}
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			todo_count[y]++;
		}
		cin >> W;

		queue<int> q;
		for (int i = 1; i <= N; i++) {
			if (todo_count[i] == 0) {
				q.push(i);
				dp_times[i] = times[i];
			}
		}

		int flag = 0;
		while (1) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < adj[now].size(); i++) {
				todo_count[adj[now][i]]--;
				if (todo_count[adj[now][i]] == 0) q.push(adj[now][i]);
				int temp = dp_times[now] + times[adj[now][i]];
				if (dp_times[adj[now][i]] < temp) dp_times[adj[now][i]] = temp;

				if (todo_count[W] == 0) {
					flag = 1;
					break;
				}
			}

			if (flag == 1) break;
		}

		cout << dp_times[W] << '\n';

		for (int i = 1; i <= N; i++) {
			times[i] = 0;
			dp_times[i] = 0;
			todo_count[i] = 0;
			adj[i].clear();
		}
	}
}