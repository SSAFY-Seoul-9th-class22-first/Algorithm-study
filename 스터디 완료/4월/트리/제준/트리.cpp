#include <iostream>
#include <queue>
using namespace std;

int parent[505];
int DAT[505];
queue<int> vec_del;

int find(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

void uni(int x, int y) {
	int px = find(x);
	int py = find(y);
	if (px == py) {
		vec_del.push(px);
		return;
	}
	parent[py] = px;
}

int main() {
	int test_case = 0;

	while (1) {
		int N, M;
		int cnt = 0;
		
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		test_case++;

		for (int i = 1; i <= N; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			uni(x, y);
		}

		for (int i = 1; i <= N; i++) {
			DAT[find(i)]++;
		}

		int cur = vec_del.size();
		for (int i = 0; i < cur; i++) {
			int now = vec_del.front();
			vec_del.pop();
			vec_del.push(find(now));
		}

		cur = vec_del.size();
		for (int i = 0; i < cur; i++) {
			int now = vec_del.front();
			vec_del.pop();
			DAT[now] = 0;
		}

		for (int i = 1; i <= N; i++) {
			if (DAT[i] != 0) cnt++;
		}
		
		if (cnt == 0) cout << "Case " << test_case << ": No trees." << '\n';
		else if (cnt == 1) cout << "Case " << test_case << ": There is one tree." << '\n';
		else cout << "Case " << test_case << ": A forest of " << cnt << " trees." << '\n';

		for (int i = 1; i <= N; i++) {
			DAT[i] = 0;
		}
	}
	
}