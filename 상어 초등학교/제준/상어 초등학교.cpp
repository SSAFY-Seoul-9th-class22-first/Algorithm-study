#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> order;
vector<int> like[404] = {};
int MAP[22][22] = {};
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct Node {
	int x;
	int y;
	// 인접한 칸 중 좋아하는 학생 수
	int like_student;
	// 인접한 칸 중 비어 있는 칸의 수
	int empty;
};

bool cmp(Node n, Node m) {
	if (n.like_student > m.like_student) return true;
	if (n.like_student < m.like_student) return false;

	if (n.empty > m.empty) return true;
	if (n.empty < m.empty) return false;

	if (n.x < m.x) return true;
	if (n.x > m.x) return false;

	if (n.y < m.y) return true;
	if (n.y > m.y) return false;
	return false;
}

void place(int num) {
	vector<Node> vec;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] == 0) {
				int cnt_like = 0;
				int cnt_empty = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					for (int l = 0; l < 4; l++) {
						if (like[num][l] == MAP[nx][ny]) cnt_like++;
					}
					if (MAP[nx][ny] == 0) cnt_empty++;
				}
				vec.push_back({ i, j, cnt_like, cnt_empty });
			}
		}
	}
	sort(vec.begin(), vec.end(), cmp);
	MAP[vec[0].x][vec[0].y] = num;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N * N; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		order.push_back(a);
		like[a].push_back(b);
		like[a].push_back(c);
		like[a].push_back(d);
		like[a].push_back(e);
	}

	for (int i = 0; i < N * N; i++) {
		place(order[i]);
	}

	int total_score = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int like_score = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				for (int l = 0; l < 4; l++) {
					if (like[MAP[i][j]][l] == MAP[nx][ny]) like_score++;
				}
			}
			if (like_score == 0) continue;
			else if (like_score == 1) total_score += 1;
			else if (like_score == 2) total_score += 10;
			else if (like_score == 3) total_score += 100;
			else total_score += 1000;
		}
	}
	cout << total_score;
}