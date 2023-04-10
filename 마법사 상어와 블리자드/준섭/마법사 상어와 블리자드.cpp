#include <iostream>
#include <queue>

using namespace std;

struct node {
	int y, x;
};

node shark;

int n, m;
int arr[50][50];
int beads[4];
int direction[2][5] = {
	0, -1, 1, 0, 0,
	0, 0, 0, -1, 1
};
int nextDirection[5] = {
	0, 3, 4, 2, 1
};

void init();

int moveArr() {
	int returnFlag = 0;
	vector<int> tmpv;
	vector<int> v;
	node now = shark;

	int dir = 3; // 시작 방향
	int dirCnt = 1;
	int beforeValue = 0;
	int cnt = 0;
	int whileFlag = 0;

	while (1) {
		
		for (int t = 0; t < dirCnt; t++) {
			
			int dy = now.y + direction[0][dir];
			int dx = now.x + direction[1][dir];
			
			if (dy == 1 && dx == 0) { 
				whileFlag = 1;
				if (tmpv.size() >= 4) {
					beads[tmpv[0]] += tmpv.size();
					returnFlag = 1;
				}
				else {
					for (int i = 0; i < tmpv.size(); i++) {
						v.push_back(tmpv[i]);
					}
				}
				break; 
			}

			if (arr[dy][dx] > 0) {
				// 이전꺼랑 같을 때
				if (beforeValue == arr[dy][dx]) {
					tmpv.push_back(arr[dy][dx]);
				}

				// 이전꺼랑 다를 때
				else {
					// 임시 저장소의 크기가 4이상이면 폭발!
					if (tmpv.size() >= 4) {
						beads[tmpv[0]] += tmpv.size();
						tmpv.clear();
						returnFlag = 1;
					}

					// 임시 저장소의 크기가 4 미만이면 최종 벡터에 업데이트
					else {
						for (int i = 0; i < tmpv.size(); i++) {
							v.push_back(tmpv[i]);
						}
						tmpv.clear();
					}

					tmpv.push_back(arr[dy][dx]);
					beforeValue = arr[dy][dx];
				}
				arr[dy][dx] = 0;
			}

			

			now = { dy, dx };
		}
		if (whileFlag) break;
		if (dir == 2 || dir == 1) dirCnt++;
		dir = nextDirection[dir];
	}


	dir = 3;
	dirCnt = 1;
	int index = 0;
	now = shark;
	int ff = 0;
	while (1) {

		for (int t = 0; t < dirCnt; t++) {
			if (v.size() == index) {
				ff = 1;
				break;
			}

			int dy = now.y + direction[0][dir];
			int dx = now.x + direction[1][dir];

			if (dy == 1 && dx == 0) {
				ff = 1;
				break;
			}
			arr[dy][dx] = v[index];
			index++;
			now = { dy, dx };
		}
		if (ff) break;
		if (dir == 2 || dir == 1) dirCnt++;
		dir = nextDirection[dir];
	}
	
	return returnFlag;
}

void changeArr() {
	int returnFlag = 0;
	vector<int> tmpv;
	vector<int> v;
	node now = shark;

	int dir = 3; // 시작 방향
	int dirCnt = 1;
	int beforeValue = 0;
	int cnt = 0;
	int whileFlag = 0;

	while (1) {


		for (int t = 0; t < dirCnt; t++) {

			int dy = now.y + direction[0][dir];
			int dx = now.x + direction[1][dir];

			//if (dy == 1 && dx == 0) {
			//	whileFlag = 1;
			//	// 나머지 tmpv 처리해주기
			//	break;
			//}
			if (arr[dy][dx] == 0) {
				whileFlag = 1;
				if (v.size() > 0) {
					v.push_back(tmpv.size());
					v.push_back(tmpv[0]);
				}
				break;
			}
			else {
				// 이전꺼랑 같을 때
				if (beforeValue == arr[dy][dx]) {
					tmpv.push_back(arr[dy][dx]);
				}

				// 이전꺼랑 다를 때
				else {
					if (tmpv.size() > 0) {
						v.push_back(tmpv.size());
						v.push_back(tmpv[0]);
					}
					tmpv.clear();
					tmpv.push_back(arr[dy][dx]);
					beforeValue = arr[dy][dx];
					
				}
				arr[dy][dx] = 0;
			}
			now = { dy, dx };
		}
		if (whileFlag) break;
		if (dir == 2 || dir == 1) dirCnt++;
		dir = nextDirection[dir];
	}

	dir = 3;
	dirCnt = 1;
	int index = 0;
	now = shark;
	int ff = 0;
	while (1) {

		for (int t = 0; t < dirCnt; t++) {

			if (v.size() == index) return;

			int dy = now.y + direction[0][dir];
			int dx = now.x + direction[1][dir];

			if (dy == 1 && dx == 0) {
				ff = 1;
				break;
			}
			arr[dy][dx] = v[index];
			index++;
			now = { dy, dx };
		}

		if (dir == 2 || dir == 1) dirCnt++;
		dir = nextDirection[dir];
	}
}


void magic(int d, int s) {

	node now = shark;

	while (s--) {
		int dy = now.y + direction[0][d];
		int dx = now.x + direction[1][d];

		if (dy == 0 or dx == 0 or dy == n + 1 or dx == n + 1) break;

		arr[dy][dx] = 0;

		now.y = dy; now.x = dx;
	}
}


void solve() {
	
	while (m--) {
		int magicDirection, magicDistance;
		cin >> magicDirection >> magicDistance;
		magic(magicDirection, magicDistance);
		while (moveArr());
		changeArr();
	} 

}

int main() {

	init();
	solve();
	cout << beads[1] * 1 + beads[2] * 2 + beads[3] * 3;
	return 0;
}

void init() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	
	shark = { (n + 1) / 2, (n + 1) / 2 };
}