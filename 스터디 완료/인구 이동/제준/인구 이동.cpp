#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, L, R;
int MAP[51][51] = {};
int time = 0;

int parent[2501] = {};
vector<int> vec[2501] = {};

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
	int px = find(x);
	int py = find(y);
	if (px == py) return;
	parent[px] = py;
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
	while (1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				parent[i * N + j] = i * N + j;
			}
		}

		int flag = 0;

		// 국경선이 열려있는 곳이 있는지 확인
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - 1; j++) {
				if (abs(MAP[i][j] - MAP[i][j + 1]) >= L && abs(MAP[i][j] - MAP[i][j + 1]) <= R) {
					flag = 1;
					uni(i * N + j, i * N + j + 1);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - 1; j++) {
				if (abs(MAP[j][i] - MAP[j + 1][i]) >= L && abs(MAP[j][i] - MAP[j + 1][i]) <= R) {
					flag = 1;
					uni(j * N + i, (j + 1) * N + i);
				}
			}
		}

		// 있으면 연합 진행
		if (flag == 1) {
			time++;
			for (int i = 0; i < N * N; i++) {
				vec[find(i)].push_back(i);
			}
			for (int i = 0; i < N * N; i++) {
				if (vec[i].size() >= 2) {
					int sum = 0;
					for (int j = 0; j < vec[i].size(); j++) {
						sum += MAP[vec[i][j] / N][vec[i][j] % N];
					}
					sum /= vec[i].size();
					for (int j = 0; j < vec[i].size(); j++) {
						MAP[vec[i][j] / N][vec[i][j] % N] = sum;
					}
				}
			}

			for (int i = 0; i < N * N; i++) {
				vec[i].clear();
			}
		}

		// 없으면 멈춤
		if (flag == 0) break;
	}

	cout << time;
}