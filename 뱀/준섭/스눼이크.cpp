#include <iostream>
#include <queue>

using namespace std;

struct node {
	int y, x;
};

int d[2][4] = {
	-1, 0, 1, 0,
	0, 1, 0, -1
};
char m[10101];
int n, k, l;
int arr[101][101];
int path[101][101];

int main() {
	queue<node> q; // 뱀 경로
	q.push({ 1, 1 });
	node now = { 1, 1 };
	int dir = 1; // 오른쪽으로 먼저 시작
	int ans = 0;
	path[1][1] = 1; //

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int appleY, appleX;
		cin >> appleY >> appleX;
		arr[appleY][appleX] = 1;
	}

	cin >> l;
	for (int i = 0; i < l; i++) {
		int num; char c;
		cin >> num >> c;
		m[num] = c;
	}

	int flag = 0;
	while (1) {
		ans++;
		int dy = now.y + d[0][dir];
		int dx = now.x + d[1][dir];
		if (dy == 0 or dx == 0 or dy > n or dx > n) {
			break;
		}
		if (path[dy][dx] == 1) {
			break;
		}
		if (arr[dy][dx] == 1) {
			// 뱀이 사과를 쳐먹으면
			arr[dy][dx] = 0;
			q.push({ dy, dx });
			path[dy][dx] = 1;
		}
		else {
			// 안쳐먹으면
			path[q.front().y][q.front().x] = 0;
			path[dy][dx] = 1;
			q.pop();
			q.push({ dy, dx });
		}
		now = { dy, dx };
		if (m[ans] == 'D') {
			dir++;
			dir %= 4;
		}
		else if (m[ans] == 'L') {
			dir--;
			if (dir == -1) dir = 3;
		}
	}
	
	cout << ans;
	return 0;
}