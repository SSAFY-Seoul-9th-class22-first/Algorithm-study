#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> pipii;
vector<pii> xv, yv, zv;
vector<pipii> v;
int n;
int parent[101010];

int Find(int num) {
	if (parent[num] == num) return num;

	return parent[num] = Find(parent[num]);
}

bool Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);

	if (A == B) return false;

	parent[B] = A;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		xv.push_back({ x, i });
		yv.push_back({ y, i });
		zv.push_back({ z, i });
		parent[i] = i;
	}



	sort(xv.begin(), xv.end());
	sort(yv.begin(), yv.end());
	sort(zv.begin(), zv.end());

	for (int i{}; i < n - 1; i++) {
		v.push_back({ abs(xv[i].first - xv[i + 1].first), {xv[i].second, xv[i + 1].second} });
		v.push_back({ abs(yv[i].first - yv[i + 1].first), {yv[i].second, yv[i + 1].second} });
		v.push_back({ abs(zv[i].first - zv[i + 1].first), {zv[i].second, zv[i + 1].second} });
	}
	
	sort(v.begin(), v.end());

	int cnt = 0;
	int ans = 0;
	for (int i{}; i < v.size(); i++) {
		if (cnt == n) break;
		if (Union(v[i].second.first, v[i].second.second)) {
			ans += v[i].first;
			cnt++;
		}
	}
	cout << ans;
	return 0;
}