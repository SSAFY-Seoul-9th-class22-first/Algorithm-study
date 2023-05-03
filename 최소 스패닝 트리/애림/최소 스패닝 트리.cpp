#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10001];

int Find(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[y] = x;
}

bool isSame(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y)return true;
	else return false;
}

int main() {

	int vertex, e;

	cin >> vertex >> e;

	int result = 0;

	vector<pair<int, pair<int, int>>>v;

	for (int i = 0; i < e; i++) 
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v.push_back({ cost,{from,to} });
	}

	sort(v.begin(), v.end());


	for (int i = 1; i <= vertex; i++)
		parent[i] = i;

	for (int i = 0; i < v.size(); i++)
	{
		if (!isSame(v[i].second.first, v[i].second.second)) {
			Union(v[i].second.first, v[i].second.second);
			result += v[i].first;
		}
	}
	cout << result;
}