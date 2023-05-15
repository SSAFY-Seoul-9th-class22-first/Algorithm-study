#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v;
int r, c;
int visited[30];
int d[2][4] = {
	-1, 0, 1, 0,
	0, 1, 0, -1
};
int cnt = 1;
int ans = 1;
void dfs(int y, int x) {

	for (int dir = 0; dir < 4; dir++) {
		int dy = y + d[0][dir];
		int dx = x + d[1][dir];

		if (dy < 0 || dx < 0 || dy == r || dx == c)continue;
		if (visited[v[dy][dx]] == 1) continue;
		visited[v[dy][dx]] = 1;
		cnt++;
		ans = max(cnt, ans);
		dfs(dy, dx);
		cnt--;
		visited[v[dy][dx]] = 0;

	}

}

int main() {

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	visited[v[0][0]] = 1;
	dfs(0, 0);

	cout << ans;
	return 0;
}