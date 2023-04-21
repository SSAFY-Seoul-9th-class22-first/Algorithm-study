#include <iostream>
#include <vector>

using namespace std;

struct node {
	int num, b;
};
vector<node> v[10101];
int ans;
int visited[10101];

void dfs(int num, int sum) {
	if (visited[num] == 1) {
		return;
	}

	if (ans < sum) {
		ans = sum;
	}

	visited[num] = 1;

	for (int i = 0; i < v[num].size(); i++) {
		dfs(v[num][i].num, sum + v[num][i].b);
	}
	

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int from, to, b;
		cin >> from >> to >> b;
		v[from].push_back({ to, b });
		v[to].push_back({ from, b });
	}

	for (int i = 1; i <= n; i++) {
		dfs(i, 0);
		for (int i = 1; i <= n; i++) visited[i] = 0;
	}
	cout << ans;

	return 0;
}