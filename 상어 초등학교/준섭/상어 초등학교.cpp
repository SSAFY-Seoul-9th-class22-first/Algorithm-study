#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct pp {
	int num;
	int like[4];
};

struct node {
	int y, x;
};

struct nextDir {
	int y, x;
	int forCnt, zeroCnt;
	bool operator < (nextDir right) const {
		if (forCnt < right.forCnt) return true;
		if (forCnt > right.forCnt) return false;
		if (zeroCnt < right.zeroCnt) return true;
		if (zeroCnt > right.zeroCnt) return false;
		if (y > right.y) return true;
		if (y < right.y) return false;
		if (x > right.x) return true;
		if (x < right.x) return false;
		return false;
	}
};
vector<int> saveArr[401];
int arr[21][21];
int p[5] = {
	0, 1, 10, 100, 1000
};
int n;
queue<pp> q;
pp now;
int d[2][4] = {
	-1, 0, 1, 0,
	 0, 1, 0, -1
};

node c1() {
	int visited[21][21] = { 0 };
	visited[1][1] = 1;
	priority_queue<nextDir> pq;
	
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			// 배열에 미리 존재하면 어짜피 못넣음
			if (arr[y][x] != 0) continue;

			// 좋아하는 학생, 비어있는 칸 체크
			int zeroCnt = 0;
			int forCnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int dy = y + d[0][dir];
				int dx = x + d[1][dir];
				if (dy < 0 or dx < 0 or dy == n or dx == n) continue;
				// 비어있는 칸 체크
				if (arr[dy][dx] == 0) {
					zeroCnt++;
					continue;
				}
				// 좋아하는 학생 찾기
				for (int i = 0; i < 4; i++) {
					if (now.like[i] == arr[dy][dx]) {
						forCnt++;
						break;
					}
				}
				
			}
			pq.push({ y, x, forCnt, zeroCnt });
		}
	}

	node nextReturn = { pq.top().y, pq.top().x };
	return nextReturn;
}

int ansFind(int y, int x) {
	int cnt = 0;
	for (int dir = 0; dir < 4; dir++) {
		int dy = y + d[0][dir];
		int dx = x + d[1][dir];
		if (dy < 0 or dx < 0 or dy == n or dx == n) continue;

		for (int i = 0; i < 4; i++) {
			if (saveArr[arr[y][x]][i] == arr[dy][dx]) {
				cnt++;
				break;
			}
		}
	}
	return cnt;

}

int main() {

	cin >> n;

	for (int i = 0; i < n * n; i++) {
		int num;
		int a[4] = { 0 };
		cin >> num >> a[0] >> a[1] >> a[2] >> a[3];
		q.push({ num, a[0], a[1], a[2], a[3]});
		for (int i = 0; i < 4; i++) {
			saveArr[num].push_back(a[i]);
		}
	}

	arr[1][1] = q.front().num;
	q.pop();
	while (!q.empty()) {
		now = q.front();
		q.pop();
		node next = c1();
		arr[next.y][next.x] = now.num;
	
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n;j++) {
			ans += p[ansFind(i, j)];
		}
		
	}

	cout << ans;
	return 0;
}