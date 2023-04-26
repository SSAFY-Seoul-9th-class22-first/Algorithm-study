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
using ll = long long int ;

int n, m, k;
ll tree[4 * 1000100];

struct query {
	ll a, b, c;
};

vector<ll> numbers;
vector<query> querys;

ll init(int st, int ed, int node) {
	if (st == ed) return tree[node] = numbers[st];
	int mid = (st + ed) / 2;
	return tree[node] = init(st, mid, node * 2) + init(mid + 1, ed, node * 2 + 1);
}

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		ll a; cin >> a; numbers.push_back(a); 
	}
	for (int i = 0; i < m + k; ++i) {
		ll a, b, c;
		cin >> a >> b >> c;
		querys.push_back({a,b,c});
 	}
	init(0, n - 1, 1);
}


ll calSum(int st, int ed, int node, int left, int right) {
	if (left > ed || right < st) return 0;
	if (left <= st && ed<=right) return tree[node];
	int mid = (st + ed) / 2;
	return calSum(st, mid, node * 2, left, right) + calSum(mid + 1, ed, node * 2 + 1, left, right);
}

void update(int st, int ed, int node, int idx, ll diff) {
	if (idx < st || idx > ed) return;
	tree[node] += diff;
	if (st == ed) return;
	int mid = (st + ed) / 2;
	update(st, mid, node * 2, idx, diff);
	update(mid+1, ed, node * 2+1 , idx, diff);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	for (int i = 0; i < m + k; ++i) {
		query now = querys[i];
		if (now.a == 1) {
			ll diff = now.c - numbers[now.b-1];
			numbers[now.b-1] = now.c;
			update(0, n - 1, 1, now.b-1, diff);
		}
		if (now.a == 2) {
			ll ret = calSum(0, n-1, 1, now.b-1, now.c-1);
			cout << ret << "\n";
		}
	}
	return 0;
}
