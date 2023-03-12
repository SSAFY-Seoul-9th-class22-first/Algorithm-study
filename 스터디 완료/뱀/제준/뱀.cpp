#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int K;
int apples[102][102] = {};
int L;
vector<pair<int, int>> snake;
queue<pair<int, char>> q;

// 방향 D, R, U, L
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		apples[x][y] = 1;
	}
	cin >> L;

	// 시간과 바꿀 방향을 queue에 저장
	for (int i = 0; i < L; i++) {
		int times;
		char ch;
		cin >> times >> ch;
		q.push({ times, ch });
	}

	// 초기 설정
	int time = 0;
	snake.push_back({ 1,1 });
	int x = 1;
	int y = 1;
	int direc = 1;
	int change_time = q.front().first;
	char change_dir = q.front().second;
	q.pop();

	while (true) {
		time++;
		int flag = 0;
		int nx = x + dx[direc];
		int ny = y + dy[direc];
		if (nx <= 0 || ny <= 0 || nx > N || ny > N) break;
		for (int i = 0; i < snake.size(); i++) {
			if (snake[i].first == nx && snake[i].second == ny) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;

		// 이동했다잉
		x = nx;
		y = ny;

		// 사과가 있으면 길이만 늘어나고
		if (apples[nx][ny] == 1) {
			snake.push_back({ nx, ny });
			apples[nx][ny] = 0;
		}
		// 사과가 없으면 길이가 그대로
		else {
			snake.erase(snake.begin());
			snake.push_back({ nx,ny });
		}

		// 방향 바꿀 시간이 되었으면 바꾼다
		if (time == change_time) {
			if (change_dir == 'L') direc = (direc + 1) % 4;
			if (change_dir == 'D') direc = (direc + 3) % 4;
			if (!q.empty()) {
				change_time = q.front().first;
				change_dir = q.front().second;
				q.pop();
			}
		}


	}
	cout << time;
}