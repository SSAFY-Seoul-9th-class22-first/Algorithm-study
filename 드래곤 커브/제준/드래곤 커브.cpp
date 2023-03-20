#include <iostream>
#include <vector>
using namespace std;

int N;
int MAP[101][101] = {};
// 오른쪽, 위쪽, 왼쪽, 아래쪽
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0,-1,0 };

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		swap(x, y);
		MAP[x][y] = 1;

		vector<int> vec;
		vector<int> vec2;
		vec.push_back(d);

		x = x + dx[d];
		y = y + dy[d];
		MAP[x][y] = 1;


		while (g--) {
			d = (d + 1) % 4;
			vec.push_back(d);
			x = x + dx[d];
			y = y + dy[d];
			MAP[x][y] = 1;

			for (int i = 0; i < vec2.size(); i++) {
				if (d + vec2[i] < 0) d = d + vec2[i] + 4;
				else d = (d + vec2[i]) % 4;
				vec.push_back(d);
				x = x + dx[d];
				y = y + dy[d];
				MAP[x][y] = 1;
			}

			vec2.clear();

			for (int i = vec.size() - 2; i >= 0; i--) {
				vec2.push_back(vec[i] - vec[i + 1]);
			}

		}
	}

	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (MAP[i][j] == 1 && MAP[i][j + 1] == 1 && MAP[i + 1][j] == 1 && MAP[i + 1][j + 1] == 1) cnt++;
		}
	}
	cout << cnt;
}