#include <iostream>
#include <vector>

using namespace std;
int n, m;
int arr[505][505];
int visited[505][505];
int sum;
int MAX;
struct node{
	int y, x;
};
vector<node> v;
int d[2][4] = {
	-1, 0, 1, 0,
	0, 1, 0, -1
};
void dfs(int level, int y, int x) {
	if (level == 3) {
		if (sum > MAX) {
			MAX = sum;
		}
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int dy = y + d[0][dir]; int dx = x + d[1][dir];
		if (dy == 0 or dx == 0 or dy > n or dx > m) continue;
		if (visited[dy][dx] == 1) continue;
		visited[dy][dx] = 1;
		sum += arr[dy][dx];
		v.push_back({ dy, dx });
		dfs(level + 1, dy, dx);
		visited[dy][dx] = 0;
		sum -= arr[dy][dx];
		v.pop_back();
	}
}

int main() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			v.push_back({ i, j });
			visited[i][j] = 1;
			sum += arr[i][j];
			dfs(0, i, j);
			sum -= arr[i][j];
			visited[i][j] = 0;
			v.pop_back();
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int c[4] = { 0 };
			int forSum = arr[i][j];
			for (int dir = 0; dir < 4; dir++) {
				c[dir] = arr[i + d[0][dir]][j + d[1][dir]];
				forSum += c[dir];
			}
			if (MAX >= forSum) continue;
			for (int num = 0; num < 4; num++) {
				forSum -= c[num];
				if (MAX < forSum) MAX = forSum;
				forSum += c[num];
			}
		}
	}


	cout << MAX;
	return 0;
}