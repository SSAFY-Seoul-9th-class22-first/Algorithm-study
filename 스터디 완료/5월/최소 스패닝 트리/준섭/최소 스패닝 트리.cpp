#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10101];
//          가중치, from, to
vector<pair<int, pair<int, int>>>v;

int Find(int num) {
	if (parent[num] == num) return num;
	else return parent[num] = Find(parent[num]);
}

int Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);

	if (A == B) return 0;

	parent[B] = A;
	return 1;
}

int main() {

	int V, E;
	int ans = 0;
	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= V; i++) parent[i] = i;

	for (int i = 0; i < v.size(); i++) {
		if (Union(v[i].second.first, v[i].second.second)) {
			ans += v[i].first;
		}
	}
	
	cout << ans;
	return 0;
}