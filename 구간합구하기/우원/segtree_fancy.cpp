// https://www.acmicpc.net/problem/1275

#include <string>
#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
using ll = long long int;

int n, m;
vector<ll> numbers;
ll tree[100100 * 4];

void input() {
	cin >> n >> m;
	numbers.assign(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}
}

ll maketree(int s = 0, int e = n - 1, int x = 1) {
	if (s == e) return tree[x] = numbers[s];
	int mid = s + e >> 1;
	ll left = maketree(s, mid, x << 1);
	ll right = maketree(mid + 1, e, x << 1 | 1);
	return tree[x] = left + right;
}


ll query(int l, int r, int s = 0, int e = n - 1, int x = 1) {
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return tree[x];
	int mid = s + e >> 1;
	return query(l, r, s, mid, x << 1) + query(l, r, mid + 1, e, x << 1 | 1);
}

void update(int idx, ll diff, int s = 0, int e = n - 1, int x = 1) {
	if (idx < s || idx > e) return;
	tree[x] += diff;
	if (s == e) return;
	int mid = s + e >> 1;
	update(idx, diff, s, mid, x << 1);
	update(idx, diff, mid+1, e, x << 1|1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	input();
	maketree();

	for (int i = 0; i < m; ++i) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int l = a < b ? a : b;
		int r = a < b ? b : a;
		cout << query(l-1, r-1) << "\n";
		ll diff = d - numbers[c - 1];
		numbers[c - 1] = d;
		update(c-1, diff);
	}
	return 0;
}
