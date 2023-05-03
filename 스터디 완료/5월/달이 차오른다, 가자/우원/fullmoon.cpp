#include <string>
#include <iostream>
#include <queue>
#include <cstring>
#include <set>
#include <algorithm>

#define R first
#define C second
using namespace std;
using pii = pair<int, int>;

string Map[55];
int vst[55][55][65];

int n, m;
vector<pii> targets;
struct mo { 
	int r, c, key,cost;

};
pii st;
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> Map[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (Map[i][j] == '1') targets.push_back({ i,j });
			else if (Map[i][j] == '0') st = { i,j };
			for (int k = 0; k < 65; ++k) vst[i][j][k] = 21e8;
		}
	}
}

int bfs() {
	queue<mo>q;
	vst[st.R][st.C][0] = 1;
	q.push({ st.R, st.C, 0,0});
	int ret = 21e8;
	while (!q.empty()) {
		mo now = q.front(); q.pop();
		vst[now.r][now.c][now.key] = now.cost;
		for (int i = 0; i < 4; ++i) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];
			int key = now.key;
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (Map[nr][nc] == '#') continue;
			if ('a' <= Map[nr][nc] && Map[nr][nc] <= 'f') key = key | (1 << (Map[nr][nc] - 'a'));
			if ('A' <= Map[nr][nc] && Map[nr][nc] <= 'F' &&  (key & (1 << (Map[nr][nc]-'A'))) == 0) continue;
			if (vst[nr][nc][key] <= now.cost+1) continue;
			if (Map[nr][nc] == '1') ret = min(ret, now.cost + 1);
			vst[nr][nc][key] = now.cost + 1;
			q.push({ nr,nc, key, now.cost + 1 });
		}
	}

	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	int ret = bfs();
	if (ret == 21e8) cout << -1;
	else cout << ret;

	return 0;
}
