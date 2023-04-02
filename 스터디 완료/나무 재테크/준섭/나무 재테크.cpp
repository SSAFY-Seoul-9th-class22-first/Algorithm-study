#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> map[11][11];			//나무 벡터
int winter[11][11] = { 0, };			//매년 더해질 양분 ( 입력으로 값 받음)
int ground[11][11] = { 0, };		//땅의 현재 남은 양분을 저장할 배열
struct tree { 
	int x, y, age;
};		
int n, m, k;				//땅 크기, 나무개수, k년
vector<tree>dead;			//죽은 나무 벡터

int d[2][8] = { -1,-1,-1,0,0,+1,+1,+1,
				-1,0,+1,-1,+1,-1,0,+1 };

void input() {
	cin >> n >> m >> k;
	//맨 처음 땅 양분은 모두 5
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			ground[r][c] = 5;
		}
	}
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			cin >> winter[r][c];
		}
	}
	//m개 나무 입력
	for (int i = 0; i < m; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		map[x][y].push_back(age);
	}
}
int main() {
	input();
	while (k--) {
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {
				sort(map[r][c].begin(), map[r][c].end());
			}
		}
		//봄
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {
				for (int i = 0; i < map[r][c].size(); i++) {
					if (ground[r][c] >= map[r][c][i]) {//양분 냠냠
						ground[r][c] = ground[r][c] - map[r][c][i];//양분먹고
						map[r][c][i]++;//나이 1증가
					}
					else {//양분 못먹음
						dead.push_back({ r,c,map[r][c][i] });
						map[r][c].erase(map[r][c].begin() + i);//죽음
						i--;//vector.erase로 인덱스 밀림 방지
					}
				}
			}
		}
		// 여름
		for (int i = dead.size() - 1; i >= 0; i--) {
			int r = dead[i].x;
			int c = dead[i].y;
			ground[r][c] = ground[r][c] + dead[i].age / 2;
		}
		dead.clear();
		// 가을
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {
				for (int i = 0; i < map[r][c].size(); i++) {
					if (map[r][c][i] % 5 == 0 and map[r][c][i] >= 5) {
						for (int j = 0; j < 8; j++) {
							int nx = r + d[0][j];
							int ny = c + d[1][j];
							if (1 <= nx and nx <= n and 1 <= ny and ny <= n) {
								map[nx][ny].push_back(1);
							}
						}
					}
				}
			}
		}
		// 겨울
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {
				ground[r][c] = ground[r][c] + winter[r][c];
			}
		}
	}
	int answer = 0;
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			answer = answer + map[r][c].size();
		}
	}
	cout << answer;
	return 0;
}