#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, fuel;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int MAP[21][21] = {};
int taxi_x;
int taxi_y;
int ans = 0;

struct person {
	int x;
	int y;
	int number;
	int dist;
};

vector<person> persons;
vector<pair<int, int>> destination;

bool cmp(person x, person y) {
	if (x.dist < y.dist) return true;
	if (x.dist > y.dist) return false;

	if (x.x < y.x) return true;
	if (x.x > y.x) return false;

	if (x.y < y.y) return true;
	if (x.y > y.y) return false;

	return false;
}

void bfs1(int x, int y) {
	int visited[21][21] = {};
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (MAP[nx][ny] == 1) continue;
			if (visited[nx][ny] >= 1) continue;
			visited[nx][ny] = visited[now.first][now.second] + 1;
			q.push({ nx, ny });
		}
	}

	for (int i = 0; i < persons.size(); i++) {
		if (visited[persons[i].x][persons[i].y] == 0) continue;
		persons[i].dist = visited[persons[i].x][persons[i].y] - 1;
	}
	sort(persons.begin(), persons.end(), cmp);
	if (persons[0].dist == 0 && (persons[0].x != taxi_x || persons[0].y != taxi_y)) ans = -1;
	else {
		fuel -= persons[0].dist;
		taxi_x = persons[0].x;
		taxi_y = persons[0].y;
		if (fuel <= 0) ans = -1;
	}
}

void bfs2(int x, int y, int num) {
	int visited[21][21] = {};
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (MAP[nx][ny] == 1) continue;
			if (visited[nx][ny] >= 1) continue;
			visited[nx][ny] = visited[now.first][now.second] + 1;
			q.push({ nx, ny });
		}
	}

	if (visited[destination[num].first][destination[num].second] == 0 && (destination[num].first != taxi_x || destination[num].second != taxi_y)) {
		ans = -1;
		return;
	}

	fuel -= (visited[destination[num].first][destination[num].second] - 1);
	taxi_x = destination[num].first;
	taxi_y = destination[num].second;
	if (fuel < 0) {
		ans = -1;
		return;
	}
	fuel += (visited[destination[num].first][destination[num].second] - 1) * 2;
}



int main() {
	cin >> N >> M >> fuel;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
	cin >> taxi_x >> taxi_y;
	taxi_x--;
	taxi_y--;
	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		persons.push_back({ x1 - 1, y1 - 1, i, 0 });
		destination.push_back({ x2 - 1, y2 - 1 });
	}

	while (M--) {
		bfs1(taxi_x, taxi_y);
		if (ans == -1) break;
		int temp_num = persons[0].number;
		persons.erase(persons.begin());
		bfs2(taxi_x, taxi_y, temp_num);
		if (ans == -1) break;
		ans = fuel;
	}

	cout << ans;
}