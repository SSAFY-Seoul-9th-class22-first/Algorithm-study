#include <string>
#include <iostream>
#include <queue>
#include <cstring>
#include <set>
#include <algorithm>

#define R first
#define C second
using namespace std;
using pii = pair<int, int>;

vector<pii> tree[10010];
vector<int> length[10010];
int firstdirs[10010];
int n;

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		length[i].push_back(0);
	}

	for (int i = 0; i < n-1; ++i) {
		int parent, child, cost;
		cin >> parent >> child >> cost;
		tree[parent].push_back({ child, cost });
	}
}

int dfs(int node, int sum, int firstdir) {
	length[node][0] = sum;
	firstdirs[node] = firstdir;

	int ret = 0;
	// 부모노드는 안해야해
	for (int i = 0; i < tree[node].size(); ++i) {
		pii now = tree[node][i];
		int nxt = now.first;
		int cost = now.second;
		if (node == 1) firstdir = i+1;
		int tmp = dfs(nxt, sum + cost, firstdir) + cost;
		length[node].push_back(tmp);
		ret = max(ret, tmp);
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	dfs(1, 0, 0);
	int ret = 0;
	// 0 번 인덱스에 더해야해
	for (int i = 2; i <= n; ++i) {
		int sum_ = 0; int mn = 21e8;

		pii tmp = { 0,0 };
		if (length[i].size() >= 2) {
			sort(length[i].begin() + 1, length[i].end(), greater<int>());
			tmp = length[i].size() >= 3 ? make_pair(length[i][1], length[i][2]) : make_pair(length[i][1], 0);
		}
		for (int j = 0; j < length[1].size() ; ++j) {
			if (j == firstdirs[i]) continue;
			int cmpval = length[1][j] + length[i][0];
			int sum = tmp.first + tmp.second + cmpval;
			int mn = min(tmp.second, cmpval);
			ret = max(ret, sum - mn);
		}
	}
	cout << ret << "\n";
	return 0;
}
