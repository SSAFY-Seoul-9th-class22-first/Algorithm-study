#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> tall[32323];
bool visit[32323];

void dfs(int node) {
	if (visit[node]) return;
	for (int i : tall[node]) {
		if (!visit[i]) dfs(i);
	}
	visit[node] = true;
	cout << node << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		tall[tmp2].push_back(tmp1);
	}

	queue<int> q;
	
	// 비교할 대상이 없으면 그냥 출력
	for (int i = 1; i <= N; ++i) {
		if (tall[i].empty()) {
			visit[i] = true;
			cout << i << " ";
		}
		else q.push(i);
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (visit[node]) continue;
		else dfs(node);
	}
}