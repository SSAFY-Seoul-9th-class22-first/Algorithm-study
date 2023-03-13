#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[9][9];
int visited[9][9];
int n, m;
struct node {
	int y, x;
};
int d[2][4] = {
	-1, 0, 1, 0,
	0, 1, 0, -1
};
vector<int> v[2];
vector<node> qo;
int MAX = 0;

int bfs() {
	queue<node> q;
	for (int i = 0; i < qo.size(); i++) {
		q.push(qo[i]);
	}
	
	int copyArr[9][9] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copyArr[i][j] = arr[i][j];
			visited[i][j] = 0;
		}
		
	}
	visited[q.front().y][q.front().x] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		
		for (int dir = 0; dir < 4; dir++) {
			int dy = now.y + d[0][dir];
			int dx = now.x + d[1][dir];
			if (dy < 0 or dx < 0 or dy == n or dx == m) continue;
			if (visited[dy][dx] == 1) continue;
			if (copyArr[dy][dx] == 1) continue;
			visited[dy][dx] = 1;
			copyArr[dy][dx] = 2;
			q.push({ dy, dx });
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copyArr[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
} 

void dfs(int level, int y, int x) {
	if (level == 3) {
		int cnt = bfs();
		if (cnt > MAX) MAX = cnt;
		return;
	}

	for (int i = y; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == y and j < x) continue;
			if (arr[i][j] != 0) continue;
			arr[i][j] = 1;
			dfs(level + 1, i, j);
			arr[i][j] = 0;
		}
	}
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++ ) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) qo.push_back({ i, j });
		}
	}

	dfs(0, 0, 0);
	cout << MAX;
	return 0;
}