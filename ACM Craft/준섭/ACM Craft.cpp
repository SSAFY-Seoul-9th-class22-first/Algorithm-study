#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int timeDelay[1010];
int timeSave[1010];
int n, k, w;
vector<int> v[1010];
int visited[1010];
queue<int> q;

void init();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;

	while (T--) {

		init();

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < v[now].size(); i++) {
				int next = v[now][i];
				visited[next]--;

				timeSave[next] = max(timeSave[next], timeSave[now] + timeDelay[next]);

				if (visited[next] == 0) {
					q.push(next);
				}
			}
		}


		cout <<timeSave[w] << "\n";
		for (int i = 1; i <= n; i++) {
			v[i].clear();
		}
	}

	return 0;
}

void init() {
	
	cin >> n >> k;
	
	
	for (int i = 1; i <= n; i++) {
		cin >> timeDelay[i];
		visited[i] = 0;
	}

	for (int i{}; i < k; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		visited[y]++;
	}
	
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) q.push(i);
		timeSave[i] = timeDelay[i];
	}

	cin >> w;
}