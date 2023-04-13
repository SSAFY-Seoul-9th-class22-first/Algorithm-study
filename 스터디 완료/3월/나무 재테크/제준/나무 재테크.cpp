#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int MAP[12][12];
int food[12][12];
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };

struct Node {
	int x;
	int y;
	int age;
};

vector<Node> vec;

bool cmp(Node a, Node b) {
	if (a.age > b.age) return true;
	if (a.age < b.age) return false;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			food[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		vec.push_back({ x, y, z });
	}

	vec.reserve(1000);

	sort(vec.begin(), vec.end(), cmp);

	while (K--) {
		// 봄 진행 코드
		int cursize = vec.size();
		vector<Node> dead;
		for (int i = cursize - 1; i >= 0; i--) {
			Node now = vec[i];
			if (now.age > food[now.x][now.y]) dead.push_back(now);
			else {
				food[now.x][now.y] -= now.age;
				now.age++;
				vec.push_back(now);
			}
		}

		vec.erase(vec.begin(), vec.begin() + cursize);


		// 여름 진행 코드
		if (dead.size() != 0) {
			for (int i = 0; i < dead.size(); i++) {
				food[dead[i].x][dead[i].y] += (dead[i].age / 2);
			}
		}

		// 가을 진행 코드
		int cursize2 = vec.size();
		for (int i = 0; i < cursize2; i++) {
			Node now = vec[i];
			if (now.age % 5 == 0) {
				for (int j = 0; j < 8; j++) {
					int nx = now.x + dx[j];
					int ny = now.y + dy[j];
					if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
					vec.push_back({ nx, ny, 1 });
				}
			}
		}
		sort(vec.begin(), vec.begin() + cursize2, cmp);

		// 겨울 진행 코드
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				food[i][j] += MAP[i][j];
			}
		}
	}

	cout << vec.size();
}