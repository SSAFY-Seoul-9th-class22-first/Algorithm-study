#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

struct fire {
	int m;
	int s;
	int d;
	int status = 0;
};

vector<fire> vec[55][55];


void command() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (vec[i][j].size() == 0) continue;
			int cursize = vec[i][j].size();
			for (int k = 0; k < cursize; k++) {
				fire now = vec[i][j][0];
				if (now.status == 1) continue;
				vec[i][j].erase(vec[i][j].begin());
				int nx = ((i + dx[now.d] * now.s) % N == 0) ? N : (((i + dx[now.d] * now.s) % N) + N) % N;
				int ny = ((j + dy[now.d] * now.s) % N == 0) ? N : (((j + dy[now.d] * now.s) % N) + N) % N;
				vec[nx][ny].push_back({ now.m, now.s, now.d, 1 });
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (vec[i][j].size() >= 2) {
				int mass_sum = 0;
				int speed_sum = 0;
				for (int k = 0; k < vec[i][j].size(); k++) {
					mass_sum += vec[i][j][k].m;
					speed_sum += vec[i][j][k].s;
					vec[i][j][k].status = 0;
				}
				if (mass_sum < 5) {
					vec[i][j].clear();
				}
				else {
					mass_sum /= 5;
					speed_sum /= vec[i][j].size();
					int even_or_odd = vec[i][j][0].d % 2;
					int flag = 0;
					for (int k = 1; k < vec[i][j].size(); k++) {
						if (even_or_odd != vec[i][j][k].d % 2) {
							flag = 1;
							break;
						}
					}
					vec[i][j].clear();
					if (flag == 0) {
						vec[i][j].push_back({ mass_sum, speed_sum, 0, 0 });
						vec[i][j].push_back({ mass_sum, speed_sum, 2, 0 });
						vec[i][j].push_back({ mass_sum, speed_sum, 4, 0 });
						vec[i][j].push_back({ mass_sum, speed_sum, 6, 0 });
					}
					else {
						vec[i][j].push_back({ mass_sum, speed_sum, 1, 0 });
						vec[i][j].push_back({ mass_sum, speed_sum, 3, 0 });
						vec[i][j].push_back({ mass_sum, speed_sum, 5, 0 });
						vec[i][j].push_back({ mass_sum, speed_sum, 7, 0 });
					}
				}
			}
			else if (vec[i][j].size() == 1) vec[i][j][0].status = 0;
		}
	}
}

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		// m은 질량, s는 속력, d는 방향
		int x, y, m, s, d;
		cin >> x >> y >> m >> s >> d;
		vec[x][y].push_back({ m, s, d, 0 });
	}

	while (K--) {
		command();
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (vec[i][j].size() == 0) continue;
			for (int k = 0; k < vec[i][j].size(); k++) {
				ans += vec[i][j][k].m;
			}
		}
	}
	cout << ans;
}