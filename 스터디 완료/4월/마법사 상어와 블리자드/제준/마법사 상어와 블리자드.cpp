#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bombed[4];
int MAP[51][51];
int N, M;
int shark_x;
int shark_y;
// ��, �Ʒ�, ����, ������
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };

// ��, �Ʒ�, ����, ��
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
		// d�� ����, s�� �Ÿ�
		int d, s;
		cin >> d >> s;

		// ���� �ı��ع�����
		for (int j = 1; j <= s; j++) {
			MAP[shark_x + dx[d] * j][shark_y + dy[d] * j] = 0;
		}

		// 0�� ���� �����ϰ� goosle ���Ϳ� �־������
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

		// ������ ������ ���� ��
		if (goosle.size() == 0) break;

		// ���� ���� ���ѹ�����
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

			// ���� ��Ų �Ŀ� 0�� �ƴѰ��� �ӽú��Ϳ� �־�ΰ�, �ӽú��͸� goosle���Ϳ� ����
			for (int i = 0; i < goosle.size(); i++) {
				if (goosle[i] != 0) temp_vec.push_back(goosle[i]);
			}
			goosle.clear();
			goosle.assign(temp_vec.begin(), temp_vec.end());

			// ���� ��ų�� ���̻� ���ٸ� break������ ����������
			if (flag == 0) break;
		}

		// goosle2 ���Ϳ� ���� ����, ���� ��ȣ �־��ֱ�
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

		// �� �ʱ�ȭ
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				MAP[i][j] = 0;
			}
		}

		// MAP���ٰ� goosle2 ���� ������ �־��ش�!
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

		// goosle, goosle2 ���� �ʱ�ȭ
		goosle.clear();
		goosle2.clear();
	}

	cout << bombed[1] + bombed[2] * 2 + bombed[3] * 3;
}