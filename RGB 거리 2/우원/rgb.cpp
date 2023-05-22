#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<unordered_map>
#define R first
#define C second

using namespace std;
using pii = pair<int, int>;
using ll = long long int;

int n, m;
int Map[330][330];
int cost[1010][3];
int memo[1010][3];


void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
}

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	input();
	int ret = 21e8;

	for (int st = 0; st < 3; ++st) {
		for (int first = 0; first < 3; ++first) {
			if (st == first) memo[1][first] = cost[1][first];
			else memo[1][first] = 21e8;
		}
		for (int nxt = 2; nxt <= n; ++nxt) {
			memo[nxt][0] = cost[nxt][0] + min(memo[nxt - 1][1], memo[nxt - 1][2]);
			memo[nxt][1] = cost[nxt][1] + min(memo[nxt - 1][0], memo[nxt - 1][2]);
			memo[nxt][2] = cost[nxt][2] + min(memo[nxt - 1][1], memo[nxt - 1][0]);
		}
		for (int ed = 0; ed < 3; ++ed) {
			if (st != ed)
				ret = min(ret, memo[n][ed]);
		}
	}
	cout << ret;
	return 0;

}

