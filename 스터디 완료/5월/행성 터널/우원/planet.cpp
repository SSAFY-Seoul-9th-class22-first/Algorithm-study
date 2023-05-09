#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piI = pair<int, pii>;

int n;
int pr[100100];
pii px[100100];
pii py[100100];
pii pz[100100];
vector<piI> dist;

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x, y, z; cin >> x >> y >> z;
		px[i] = { x,i }; py[i] = { y,i }; 
		pz[i] = { z,i }; pr[i] = i;
	}
}

int Find(int x) {
	if (x == pr[x]) return x;
	return pr[x] = Find(pr[x]);
}

int uni(int a, int b) {
	a = Find(a), b = Find(b);
	if (a == b) return 0;
	pr[b] = a;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	input();
	sort(px+1, px + n+1);
	sort(py+1, py + n+1);
	sort(pz+1, pz + n+1);
	for (int i = 2; i <= n; ++i) {
		dist.push_back({ abs(px[i].first - px[i - 1].first), { px[i].second, px[i - 1].second} });
		dist.push_back({ abs(py[i].first - py[i - 1].first), { py[i].second, py[i - 1].second} });
		dist.push_back({ abs(pz[i].first - pz[i - 1].first), { pz[i].second, pz[i - 1].second} });
	}
	sort(dist.begin(), dist.end());

	ll ret = 0;

	for (int i = 0; i < dist.size(); ++i) {
		piI now = dist[i];
		int a = now.second.first;
		int b = now.second.second;
		ll c = now.first;
		if (uni(a, b)) ret += c;
	}

	cout << ret;


	return 0;
}
