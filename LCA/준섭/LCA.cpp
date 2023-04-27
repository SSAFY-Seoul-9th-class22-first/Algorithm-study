#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
int check[50505];
int parent[50505];
int depth[50505];
vector<int> v[50505];

int LCA(int a, int b) {

	if (depth[a] > depth[b]) {
		// 깊이를 맞춰준다(동일 선상에서 비교해야함)
		while (depth[a] != depth[b]) a = parent[a];

		// 동일선상일 땐 계속 비교해서 같은 부모님이 계실때까지 반복
		while (a != b) {
			a = parent[a];
			b = parent[b];
		}
		
	}
	else {
		while (depth[a] != depth[b]) b = parent[b];

		while (a != b) {
			a = parent[a];
			b = parent[b];
		}
	}
	return a;
}

int main() {

	int n, m; 
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	// 1번노드부터 확인
	check[1] = 1;
	q.push(1);

	while (!q.empty()) {

		int pn = q.front();
		q.pop();
		for (int i = 0; i < v[pn].size(); i++) {
			if (check[v[pn][i]] == 0) {
				check[v[pn][i]] = 1; // 집 방문증 발급
				parent[v[pn][i]] = pn; // 부모님 등록해드리기
				depth[v[pn][i]] = depth[pn] + 1; // 지하층 뚫기
				q.push(v[pn][i]);
			}
		}

	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << endl;
	}
	return 0;
}