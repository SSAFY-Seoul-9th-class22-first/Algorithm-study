#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

#define R first
#define C second

using namespace std;
using pii = pair<int, int>;
using ll = long long int;

int n, m, ret;
string Map[22];
int vst[22][22];
int alpha[100];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> Map[i];
	}
}

void dfs(int level, int r, int c) {
	ret = max(ret, level);
	for (int i = 0; i < 4; ++i) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
		if (vst[nr][nc]) continue;
		if (alpha[Map[nr][nc]]) continue;
		alpha[Map[nr][nc]] = 1;
		vst[nr][nc] = 1;
		dfs(level + 1, nr, nc);
		vst[nr][nc] = 0;
		alpha[Map[nr][nc]] = 0;
	}
}


int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	input();
	vst[0][0] = 1;
	alpha[Map[0][0]] = 1;
	dfs(0, 0, 0);

	cout << ret+1;

	return 0;
}

