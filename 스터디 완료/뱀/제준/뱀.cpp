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

// ���� D, R, U, L
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

	// �ð��� �ٲ� ������ queue�� ����
	for (int i = 0; i < L; i++) {
		int times;
		char ch;
		cin >> times >> ch;
		q.push({ times, ch });
	}

	// �ʱ� ����
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

		// �̵��ߴ���
		x = nx;
		y = ny;

		// ����� ������ ���̸� �þ��
		if (apples[nx][ny] == 1) {
			snake.push_back({ nx, ny });
			apples[nx][ny] = 0;
		}
		// ����� ������ ���̰� �״��
		else {
			snake.erase(snake.begin());
			snake.push_back({ nx,ny });
		}

		// ���� �ٲ� �ð��� �Ǿ����� �ٲ۴�
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