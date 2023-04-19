#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <deque>
#include <cstring>
#include <set>
#include <algorithm>


using namespace std;
using pii = pair<int, int>;
int parent[505];
int iscycle[505];

int n, m;

int Find(int now) {
	if (parent[now] == now) return now;
	return parent[now] = Find(parent[now]);
}

void Union(int a, int b) {
	int pa = Find(a); int pb = Find(b);
	if (pa == pb) return;
	parent[pb] = pa;
}

void init() {
	memset(parent, 0, sizeof(parent));
	memset(iscycle, 0, sizeof(iscycle));

	for (int i = 1; i <= n; ++i) parent[i] = i;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int case_ = 1;
	while (1) {
		cin >> n >> m;
		init();
		set<int> unique;
		if (case_ == 17) {
			int de = 1;
		}
		if (n == 0 && m == 0) break;
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			int pa = Find(a); int pb = Find(b);
			if (pa == pb) {
				iscycle[pa] = 1; 
				iscycle[pb] = 1;
				continue;
			}
			Union(a, b);
		}
		for (int i = 1; i <= n; ++i) {
			if (iscycle[i]) iscycle[Find(i)] = 1;
		}
		for (int i = 1; i <= n; ++i) {
			int p = Find(parent[i]);
			if (iscycle[p]) continue;
			unique.insert(p);
		}
		int cnt = unique.size() ;
		if (cnt > 1) printf("Case %d: A forest of %d trees.\n", case_, cnt);
		else if (cnt == 1) printf("Case %d: There is one tree.\n", case_);
		else printf("Case %d: No trees.\n", case_);
		case_++;
	}
}
