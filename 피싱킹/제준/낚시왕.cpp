#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, M;
int king_index = 0;
int get_size = 0;
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

struct shark {
	int s; // 속력
	int d; // 이동 방향, 1은 위, 2는 아래, 3은 오른쪽, 4는 왼쪽
	int z; // 크기
	int moved;
};

vector<shark> vec[101][101];

bool cmp(shark x, shark y) {
	if (x.z > y.z) return true;
	if (x.z < y.z) return false;
	return false;
}

int main() {
	cin >> R >> C >> M;
	int temp = C;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		vec[r][c].push_back({ s,d,z });
	}

	while (temp--) {
		king_index++;
		for (int i = 1; i <= R; i++) {
			if (vec[i][king_index].size() == 1) {
				get_size += vec[i][king_index][0].z;
				vec[i][king_index].clear();
				break;
			}
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (vec[i][j].size() == 0) continue;
				shark now = vec[i][j][0];
				if (now.moved == 1) continue;
				vec[i][j].erase(vec[i][j].begin());
				int nx = i + dx[now.d] * now.s;
				int ny = j + dy[now.d] * now.s;
				if (nx < 1) {
					nx = nx % ((R - 1) * 2);
					if (nx > -R + 1) {
						vec[-nx + 2][ny].push_back({ now.s, 2, now.z, 1 });
					}
					else {
						vec[nx + ((R - 1) * 2)][ny].push_back({ now.s, 1, now.z, 1 });
					}
				}
				else if (nx > R) {
					nx = (nx - 2) % ((R - 1) * 2);
					if (nx >= R - 1) {
						vec[((R - 1) * 2) - nx][ny].push_back({ now.s, 1, now.z, 1 });
					}
					else {
						vec[nx + 2][ny].push_back({ now.s, 2, now.z, 1 });
					}
				}
				else if (ny < 1) {
					ny = ny % ((C - 1) * 2);
					if (ny > -C + 1) {
						vec[nx][-ny + 2].push_back({ now.s, 3, now.z, 1 });
					}
					else {
						vec[nx][ny + ((C - 1) * 2)].push_back({ now.s, 4, now.z, 1 });
					}
				}
				else if (ny > C) {
					ny = (ny - 2) % ((C - 1) * 2);
					if (ny >= C - 1) {
						vec[nx][((C - 1) * 2) - ny].push_back({ now.s, 4, now.z, 1 });
					}
					else {
						vec[nx][ny + 2].push_back({ now.s, 3, now.z, 1 });
					}
				}
				else {
					vec[nx][ny].push_back({ now.s, now.d, now.z, 1 });
				}
			}
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (vec[i][j].size() >= 2) {
					sort(vec[i][j].begin(), vec[i][j].end(), cmp);
					vec[i][j].erase(vec[i][j].begin() + 1, vec[i][j].end());
				}
				if (vec[i][j].size() == 1) vec[i][j][0].moved = 0;
			}
		}
	}

	cout << get_size;
}