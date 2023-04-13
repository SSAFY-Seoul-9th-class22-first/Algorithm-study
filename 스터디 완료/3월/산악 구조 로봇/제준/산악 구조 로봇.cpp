#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int to_x;
	int to_y;
	int cost;
	bool operator < (Edge next) const {
		if (cost < next.cost) return false;
		if (cost > next.cost) return true;
		return false;
	}
};

int map[35][35] = {};
int T;
int N, M;
int test_case;
vector<Edge> vec[35][35];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void dijkstra(int x, int y) {
	priority_queue<Edge>pq;
	pq.push({ x, y, 0 });
	int dist[35][35] = {};
	int MAX = 21e8;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = MAX;
		}
	}

	dist[x][y] = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		if (dist[now.to_x][now.to_y] < now.cost) continue;
		for (int i = 0; i < vec[now.to_x][now.to_y].size(); i++) {
			Edge next = vec[now.to_x][now.to_y][i];
			int ncost = dist[now.to_x][now.to_y] + next.cost;
			if (dist[next.to_x][next.to_y] <= ncost) continue;
			dist[next.to_x][next.to_y] = ncost;
			pq.push({ next.to_x, next.to_y, ncost });
		}
	}

	cout << "#" << test_case << " " << dist[N][N] << '\n';

}

int main() {
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
					if (map[i][j] > map[nx][ny]) vec[i][j].push_back({ nx, ny, 0 });
					else if (map[i][j] == map[nx][ny]) vec[i][j].push_back({ nx,ny,1 });
					else vec[i][j].push_back({ nx, ny, (map[nx][ny] - map[i][j]) * 2 });
				}
			}
		}

		// 터널 추가
		for (int i = 0; i < M; i++) {
			int arr[5];
			for (int j = 0; j < 5; j++) {
				cin >> arr[j];
			}
			vec[arr[0]][arr[1]].push_back({ arr[2], arr[3], arr[4] });
			vec[arr[2]][arr[3]].push_back({ arr[0], arr[1], arr[4] });
		}

		dijkstra(1, 1);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				vec[i][j].clear();
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] = 0;
			}
		}

	}
}