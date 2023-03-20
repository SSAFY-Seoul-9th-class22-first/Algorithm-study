#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[101][101];
int dir[2][4] = {
	0, -1, 0, 1,
	1, 0, -1, 0
};


int main() {

	int n; cin >> n;
	int maxY = 0; int maxX = 0;
	int minY = 987654321; int minX = 987654321;
	vector<int> v;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		arr[y][x] = 1;
		if (maxY < y) maxY = y;
		if (maxX < x) maxX = x;
		if (minY > y) minY = y;
		if (minX > x) minX = x;
		v.push_back(d);
		for (int j = 0; j < g; j++) {
			for (int z = v.size() - 1; z >= 0; z--) {
				q.push((v[z] + 1) % 4);
			}
			while (!q.empty()) {
				v.push_back(q.front());
				q.pop();
			}
		}

		for (int j = 0; j < v.size(); j++) {
			int dy = y + dir[0][v[j]]; int dx = x + dir[1][v[j]];
			arr[dy][dx] = 1;
			y = dy; x = dx;
			if (maxY < y) maxY = y;
			if (maxX < x) maxX = x;
			if (minY > y) minY = y;
			if (minX > x) minX = x;
		}
		v.clear();
	}
	int ans = 0;
	for (int i = minY - 1; i < maxY + 1; i++) {
		for (int j = minX - 1; j < maxX + 1; j++) {
			if (arr[i][j] == 1 and arr[i + 1][j + 1] == 1 and
				arr[i + 1][j] == 1 and arr[i][j + 1] == 1) ans++;
		} 
	}
	
	cout << ans;

	return 0;
}


