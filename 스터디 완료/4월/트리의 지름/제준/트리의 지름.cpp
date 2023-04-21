#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<pair<int, int>> vec[10101];
int visited[10101];
int dist = 0;
int max_dist = 0;
int temp_node = 0; // 루트 노드에서 가장 먼 노드를 저장

void dfs(int num) {
	if (max_dist < dist) {
		max_dist = dist;
		temp_node = num;
	}

	for (int i = 0; i < vec[num].size(); i++) {
		pair<int, int> now = vec[num][i];
		if (visited[now.first] == 1) continue;
		visited[now.first] = 1;
		dist += now.second;
		dfs(now.first);
		dist -= now.second;
		visited[now.first] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i < N; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		vec[x].push_back({ y,cost });
		vec[y].push_back({ x, cost });
	}

	visited[1] = 1;
	dfs(1);
	visited[1] = 0;

	int far_node = temp_node;
	max_dist = 0;

	visited[far_node] = 1;
	dfs(far_node);
	
	cout << max_dist;
}