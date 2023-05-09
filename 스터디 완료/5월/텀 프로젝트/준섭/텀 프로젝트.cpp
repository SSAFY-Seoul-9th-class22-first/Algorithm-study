#include <iostream>

using namespace std;

int n;
int arr[101010];
int visited[101010];
int cycle[101010];
int ans;

void dfs(int node) {
	visited[node] = 1;

	int next = arr[node];

	if (!visited[next]) {
		dfs(next);
	}

	else if (!cycle[next]) {
		for (int i = next; i != node; i = arr[i]) {
			ans++;
		}
		ans++;
	}
	cycle[node] = 1;
}

int main() {

	int T; cin >> T;
	while (T--) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		cout << n - ans << endl;
		for (int i = 1; i <= n; i++) {
			visited[i] = 0; cycle[i] = 0;
		}
	}

	return 0;
}