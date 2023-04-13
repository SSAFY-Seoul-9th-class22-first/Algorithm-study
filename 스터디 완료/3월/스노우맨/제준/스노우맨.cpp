#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int MAP[55][55] = {};
int snowman_x;
int snowman_y;
int jewel_x;
int jewel_y;

struct Node {
	int to_x;
	int to_y;
	int cost;
	bool operator < (Node next) const {
		if (cost < next.cost) return false;
		if (cost > next.cost) return true;
		return false;
	}
};

vector<Node> vec[55][55];

void dijkstra(int x, int y) {
	priority_queue<Node>pq;
	pq.push({ x, y, 0 });

	int ans[55][55] = {};
	int MAX = 21e8;
	// ans 배열에는 배열로 가는 경우 중 가장 낮은 높이로 이동하는 값을 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans[i][j] = MAX;
		}
	}
	ans[x][y] = 0;

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (ans[now.to_x][now.to_y] < now.cost) continue;

		for (int i = 0; i < vec[now.to_x][now.to_y].size(); i++) {
			Node next = vec[now.to_x][now.to_y][i];
			// 다음 노드의 값은 현재 ans 값과 앞으로 이동하는 높이 차의 값 중 최대값
			int ncost = max(ans[now.to_x][now.to_y], abs(next.to_x - now.to_x));
			if (ans[next.to_x][next.to_y] <= ncost) continue;
			ans[next.to_x][next.to_y] = ncost;
			pq.push({ next.to_x, next.to_y, ncost });
		}
	}

	cout << ans[jewel_x][jewel_y];
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}

	// 세로로 이동할 수 있는 경로를 벡터에 저장
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N - 1; i++) {
			for (int k = i + 1; k < N; k++) {
				if (MAP[i][j] != 0 && MAP[k][j] != 0) {
					vec[i][j].push_back({ k, j, k - i });
					vec[k][j].push_back({ i, j, k - i });
				}
			}
		}
	}

	// 가로로 이동할 수 있는 경로를 벡터에 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 1; j++) {
			if (MAP[i][j] != 0 && MAP[i][j + 1] != 0) {
				vec[i][j].push_back({ i, j + 1, 0 });
				vec[i][j + 1].push_back({ i, j, 0 });
			}
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == 2) {
				snowman_x = i;
				snowman_y = j;
			}
			if (MAP[i][j] == 3) {
				jewel_x = i;
				jewel_y = j;
			}
		}
	}

	dijkstra(snowman_x, snowman_y);

}