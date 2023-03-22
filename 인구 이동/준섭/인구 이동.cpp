#include <iostream>
#include <queue>

using namespace std;

int arr[51][51];
int visited[51][51];
struct node {
	int y, x;
};
int d[2][4] = {
	-1, 0, 1, 0,
	0, 1, 0, -1
};
int n, L, R;
int flag;

int avr[2501];

void bfs(int y, int x, int cnt) {
	queue<node> q;
	int sum = arr[y][x];
	int c = 1;
	q.push({ y, x });

	visited[y][x] = cnt;

	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int dy = now.y + d[0][dir]; int dx = now.x + d[1][dir];
			if (dy < 0 or dx < 0 or dy == n or dx == n) continue;
			if (visited[dy][dx] != 0) continue;
			if (abs(arr[now.y][now.x] - arr[dy][dx]) < L or
				abs(arr[now.y][now.x] - arr[dy][dx]) > R) continue;
			flag = 1;
			visited[dy][dx] = cnt;
			q.push({ dy, dx });
			// 각 나라들의 합과 연합된 나라의 수
			sum += arr[dy][dx];
			c++;
		}
	}
	// 넘버링 한 인덱스마다 값 갱신
	avr[cnt] = sum / c;
}

int main() {


	cin >> n >> L >> R;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
	int ans = 0;
	
	while (1){
		// 연합된 나라들 넘버링하기 위한 cnt
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n;j++) {
				if (visited[i][j] != 0) continue;
				cnt++;
				bfs(i, j, cnt);
			}
 		}
		// 하나라도 연합을 했다면
		if (flag) {
			ans++;
			flag = 0;
		}
		// 연합이 하나도 없다면
		else {
			cout << ans;
			break;
		}
		// 갱신
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 0) continue;
				arr[i][j] = avr[visited[i][j]];
				visited[i][j] = 0;
			}
		}
		
	}
	return 0;
}
