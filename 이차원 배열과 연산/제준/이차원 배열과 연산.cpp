#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r, c, k;
int MAP[101][101] = {};
int row = 3;
int col = 3;

bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.second < y.second) return true;
	if (x.second > y.second) return false;

	if (x.first < y.first) return true;
	if (x.first > y.first) return false;
	return false;
}


int main() {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> MAP[i][j];
		}
	}

	int time = 0;
	while (1) {
		if (MAP[r][c] == k) break;

		if (row >= col) {
			int mx = 0;
			for (int i = 1; i <= row; i++) {
				vector<pair<int, int>> vec;
				for (int j = 1; j <= col; j++) {
					if (MAP[i][j] == 0) continue;
					int flag = 0;
					for (int k = 0; k < vec.size(); k++) {
						if (vec[k].first == MAP[i][j]) {
							vec[k].second++;
							flag = 1;
							break;
						}
					}
					if (flag == 0) vec.push_back({ MAP[i][j], 1 });
				}
				sort(vec.begin(), vec.end(), cmp);
				for (int j = 1; j <= 100; j++) {
					MAP[i][j] = 0;
				}
				for (int j = 0; j < vec.size(); j++) {
					if (j >= 50) break;
					MAP[i][2 * j + 1] = vec[j].first;
					MAP[i][2 * j + 2] = vec[j].second;
					if (mx < (2 * j + 2)) mx = (2 * j + 2);
				}
			}
			col = mx;
		}

		else if (row < col) {
			int mx = 0;
			for (int i = 1; i <= col; i++) {
				vector<pair<int, int>> vec;
				for (int j = 1; j <= row; j++) {
					if (MAP[j][i] == 0) continue;
					int flag = 0;
					for (int k = 0; k < vec.size(); k++) {
						if (vec[k].first == MAP[j][i]) {
							vec[k].second++;
							flag = 1;
							break;
						}
					}
					if (flag == 0) vec.push_back({ MAP[j][i], 1 });
				}
				sort(vec.begin(), vec.end(), cmp);
				for (int j = 1; j <= 100; j++) {
					MAP[j][i] = 0;
				}
				for (int j = 0; j < vec.size(); j++) {
					if (j >= 50) break;
					MAP[2 * j + 1][i] = vec[j].first;
					MAP[2 * j + 2][i] = vec[j].second;
					if (mx < (2 * j + 2)) mx = (2 * j + 2);
				}
			}
			row = mx;
		}
		if (time == 100) {
			time = -1;
			break;
		}
		time++;
	}
	cout << time;
}