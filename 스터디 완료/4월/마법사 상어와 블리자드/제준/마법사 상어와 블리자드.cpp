#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bombed[4];
int MAP[51][51];
int N, M;
int shark_x;
int shark_y;
// 위, 아래, 왼쪽, 오른쪽
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };

// 왼, 아래, 오른, 위
int dx1[4] = { 0,1,0,-1 };
int dy1[4] = { -1,0,1,0 };

vector<int> goosle;
vector<int> goosle2;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}

	shark_x = (N + 1) / 2;
	shark_y = (N + 1) / 2;

	for (int i = 0; i < M; i++) {
		// d는 방향, s는 거리
		int d, s;
		cin >> d >> s;

		// 구슬 파괴해버리기
		for (int j = 1; j <= s; j++) {
			MAP[shark_x + dx[d] * j][shark_y + dy[d] * j] = 0;
		}

		// 0인 값을 제외하고 goosle 벡터에 넣어버리기
		int temp_x = shark_x;
		int temp_y = shark_y;
		int dir = 0;
		for (int i = 1; i < N - 1; i++) {
			for (int j = 0; j < i; j++) {
				temp_x += dx1[dir];
				temp_y += dy1[dir];
				if (MAP[temp_x][temp_y] != 0) goosle.push_back(MAP[temp_x][temp_y]);
			}
			dir = (dir + 1) % 4;
			for (int j = 0; j < i; j++) {
				temp_x += dx1[dir];
				temp_y += dy1[dir];
				if (MAP[temp_x][temp_y] != 0) goosle.push_back(MAP[temp_x][temp_y]);
			}
			dir = (dir + 1) % 4;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < N - 1; j++) {
				temp_x += dx1[dir];
				temp_y += dy1[dir];
				if (MAP[temp_x][temp_y] != 0) goosle.push_back(MAP[temp_x][temp_y]);
			}
			dir = (dir + 1) % 4;
		}

		// 구슬이 없으면 게임 끝
		if (goosle.size() == 0) break;

		// 구슬 폭파 시켜버리기
		int cnt = 1;
		while (1) {
			vector<int> temp_vec;
			int flag = 0;
			for (int i = 1; i < goosle.size(); i++) {
				if (goosle[i] != goosle[i - 1]) {
					if (cnt >= 4) {
						bombed[goosle[i - 1]] += cnt;
						for (int j = 1; j <= cnt; j++) {
							goosle[i - j] = 0;
						}
						flag = 1;
					}
					cnt = 1;
				}
				else cnt++;
			}
			if (cnt >= 4) {
				bombed[goosle[goosle.size() - 1]] += cnt;
				for (int j = 1; j <= cnt; j++) {
					goosle[goosle.size() - j] = 0;
				}
			}
			cnt = 1;

			// 폭파 시킨 후에 0이 아닌값을 임시벡터에 넣어두고, 임시벡터를 goosle벡터에 복사
			for (int i = 0; i < goosle.size(); i++) {
				if (goosle[i] != 0) temp_vec.push_back(goosle[i]);
			}
			goosle.clear();
			goosle.assign(temp_vec.begin(), temp_vec.end());

			// 폭파 시킬게 더이상 없다면 break문으로 빠져나오기
			if (flag == 0) break;
		}

		// goosle2 벡터에 구슬 개수, 구슬 번호 넣어주기
		cnt = 1;
		for (int i = 1; i < goosle.size(); i++) {
			if (goosle[i] != goosle[i - 1]) {
				goosle2.push_back(cnt);
				goosle2.push_back(goosle[i - 1]);
				cnt = 1;
			}
			else cnt++;
		}
		goosle2.push_back(cnt);
		goosle2.push_back(goosle[goosle.size() - 1]);

		temp_x = shark_x;
		temp_y = shark_y;
		dir = 0;
		int pointer = 0;
		int flag = 0;

		// 맵 초기화
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				MAP[i][j] = 0;
			}
		}

		// MAP에다가 goosle2 벡터 값들을 넣어준다!
		for (int i = 1; i < N - 1; i++) {
			for (int j = 0; j < i; j++) {
				temp_x += dx1[dir];
				temp_y += dy1[dir];
				MAP[temp_x][temp_y] = goosle2[pointer];
				pointer++;
				if (pointer == goosle2.size()) {
					flag = 1;
					break;
				}
			}
			if (flag == 1) break;
			dir = (dir + 1) % 4;
			for (int j = 0; j < i; j++) {
				temp_x += dx1[dir];
				temp_y += dy1[dir];
				MAP[temp_x][temp_y] = goosle2[pointer];
				pointer++;
				if (pointer == goosle2.size()) {
					flag = 1;
					break;
				}
			}
			if (flag == 1) break;
			dir = (dir + 1) % 4;
		}
		if (flag == 0) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < N - 1; j++) {
					temp_x += dx1[dir];
					temp_y += dy1[dir];
					MAP[temp_x][temp_y] = goosle2[pointer];
					pointer++;
					if (pointer == goosle2.size()) {
						flag = 1;
						break;
					}
				}
				if (flag == 1) break;
				dir = (dir + 1) % 4;
			}
		}

		// goosle, goosle2 벡터 초기화
		goosle.clear();
		goosle2.clear();
	}

	cout << bombed[1] + bombed[2] * 2 + bombed[3] * 3;
}