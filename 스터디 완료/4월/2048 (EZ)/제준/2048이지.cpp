#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int MAP[22][22];
int N;
int mx = 0;

void dfs(int level, int MAP[22][22]) {
	if (level == 5) {
		// �ִ� ã��
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (MAP[i][j] > mx) mx = MAP[i][j];
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++) {

		// ��
		if (i == 0) {
			int NEW_MAP[22][22] = {};

			// �� ������ ����
			for (int j = 0; j < N; j++) {
				queue<int> q;

				// 0�� ������ ��簪�� ť�� ����
				for (int k = 0; k < N; k++) {
					if (MAP[k][j] == 0) continue;
					q.push(MAP[k][j]);
				}

				// cur_index : ������ �ε���
				int cur_index = 0;

				if (q.size() == 0) continue;

				else if (q.size() == 1) {
					NEW_MAP[cur_index][j] = q.front();
				}

				else {
					int now = q.front();
					q.pop();
					int next = q.front();
					q.pop();
					while (1) {
						if (now == next) {
							NEW_MAP[cur_index][j] = now * 2;
							cur_index++;
							if (q.size() == 0) break;
							else if (q.size() == 1) {
								NEW_MAP[cur_index][j] = q.front();
								break;
							}
							else {
								now = q.front();
								q.pop();
								next = q.front();
								q.pop();
							}
						}
						else if (now != next) {
							NEW_MAP[cur_index][j] = now;
							cur_index++;
							now = next;
							if (q.size() == 0) {
								NEW_MAP[cur_index][j] = now;
								break;
							}
							else {
								next = q.front();
								q.pop();
							}
						}
					}
					
				}
			}
			dfs(level + 1, NEW_MAP);
		}

		// ��
		else if (i == 1) {
			int NEW_MAP[22][22] = {};
			for (int j = 0; j < N; j++) {
				queue<int> q;
				for (int k = N - 1; k >= 0; k--) {
					if (MAP[k][j] == 0) continue;
					q.push(MAP[k][j]);
				}
				int cur_index = N - 1;
				if (q.size() == 0) continue;
				else if (q.size() == 1) {
					NEW_MAP[cur_index][j] = q.front();
				}
				else {
					int now = q.front();
					q.pop();
					int next = q.front();
					q.pop();
					while (1) {
						if (now == next) {
							NEW_MAP[cur_index][j] = now * 2;
							cur_index--;
							if (q.size() == 0) break;
							else if (q.size() == 1) {
								NEW_MAP[cur_index][j] = q.front();
								break;
							}
							else {
								now = q.front();
								q.pop();
								next = q.front();
								q.pop();
							}
						}
						else if (now != next) {
							NEW_MAP[cur_index][j] = now;
							cur_index--;
							now = next;
							if (q.size() == 0) {
								NEW_MAP[cur_index][j] = now;
								break;
							}
							else {
								next = q.front();
								q.pop();
							}
						}
					}

				}
			}
			dfs(level + 1, NEW_MAP);
		}

		// ��
		else if (i == 2) {
		int NEW_MAP[22][22] = {};
		for (int j = 0; j < N; j++) {
			queue<int> q;
			for (int k = 0; k < N; k++) {
				if (MAP[j][k] == 0) continue;
				q.push(MAP[j][k]);
			}
			int cur_index = 0;
			if (q.size() == 0) continue;
			else if (q.size() == 1) {
				NEW_MAP[j][cur_index] = q.front();
			}
			else {
				int now = q.front();
				q.pop();
				int next = q.front();
				q.pop();
				while (1) {
					if (now == next) {
						NEW_MAP[j][cur_index] = now * 2;
						cur_index++;
						if (q.size() == 0) break;
						else if (q.size() == 1) {
							NEW_MAP[j][cur_index] = q.front();
							break;
						}
						else {
							now = q.front();
							q.pop();
							next = q.front();
							q.pop();
						}
					}
					else if (now != next) {
						NEW_MAP[j][cur_index] = now;
						cur_index++;
						now = next;
						if (q.size() == 0) {
							NEW_MAP[j][cur_index] = now;
							break;
						}
						else {
							next = q.front();
							q.pop();
						}
					}
				}

			}
		}
		dfs(level + 1, NEW_MAP);
		}

		// ��
		else {
		int NEW_MAP[22][22] = {};
		for (int j = 0; j < N; j++) {
			queue<int> q;
			for (int k = N - 1; k >= 0; k--) {
				if (MAP[j][k] == 0) continue;
				q.push(MAP[j][k]);
			}
			int cur_index = N - 1;
			if (q.size() == 0) continue;
			else if (q.size() == 1) {
				NEW_MAP[j][cur_index] = q.front();
			}
			else {
				int now = q.front();
				q.pop();
				int next = q.front();
				q.pop();
				while (1) {
					if (now == next) {
						NEW_MAP[j][cur_index] = now * 2;
						cur_index--;
						if (q.size() == 0) break;
						else if (q.size() == 1) {
							NEW_MAP[j][cur_index] = q.front();
							break;
						}
						else {
							now = q.front();
							q.pop();
							next = q.front();
							q.pop();
						}
					}
					else if (now != next) {
						NEW_MAP[j][cur_index] = now;
						cur_index--;
						now = next;
						if (q.size() == 0) {
							NEW_MAP[j][cur_index] = now;
							break;
						}
						else {
							next = q.front();
							q.pop();
						}
					}
				}

			}
		}
		dfs(level + 1, NEW_MAP);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}

	dfs(0, MAP);
	cout << mx;
}