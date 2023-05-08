#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int to;
	int cost;
	bool operator < (Edge next) const {
		if (cost < next.cost)
			return false;
		if (cost > next.cost)
			return true;
		return false;
	}
};

int N, M;
vector<Edge>al[10101];

int prim(int start) {
	
	priority_queue<Edge>pq;
	pq.push({ start, 0 });

	int connected[10101] = { 0, };
	int sum = 0;
	int cnt = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (connected[now.to] == 1) continue;
		connected[now.to] = 1;
		sum += now.cost;
		cnt++;

		for (int i = 0; i < al[now.to].size(); i++) {
			Edge next = al[now.to][i];
			if (connected[next.to] == 1) continue;
			pq.push(next);
		}
	}
	if (cnt == N) return sum;
	return -1;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		al[from].push_back({ to, cost });
		al[to].push_back({ from, cost });
	} 
	cout << prim(1);
}