#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct value {
	int val, cnt;
	bool operator < (value right) const {
		if (cnt > right.cnt)
			return true;
		if (cnt < right.cnt)
			return false;
		if (val > right.val)
			return true;
		if (val < right.val)
			return false;
		return false;
	}
};

priority_queue<value> q;
vector<int> v[101];
int dist[101];
int arr[101][101];


int main() {

	int r, c, k;
	cin >> r >> c >> k;
	int rowMAX = 3;
	int colMAX = 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	r--; c--;

	int t = 0;
	while (t < 101) {
		if (arr[r][c] == k) {
			cout << t;
			return 0;
		}
		if (t == 100) {
			cout << -1;
			return 0;
		}

		if (rowMAX >= colMAX) {
			// R연산 오른쪽으로 쭈욱
			int newColMAX = 0;
			for (int i = 0; i < rowMAX; i++) {
				int forMAX = 0;
				
				for (int j = 0; j < colMAX; j++) {
					if (arr[i][j] == 0) continue;
					dist[arr[i][j]]++;
					if (arr[i][j] > forMAX) forMAX = arr[i][j];
				}
				// j는 넘버, dist[j]는 j의 횟수
				for (int j = 1; j <= forMAX; j++) {
					if (dist[j] == 0) continue;
					q.push({ j, dist[j] });
					dist[j] = 0;
				}
				int index = 0;
				while (!q.empty()) {
					arr[i][index++] = q.top().val;
					arr[i][index++] = q.top().cnt;
					q.pop();	
				}
				if (newColMAX < index) newColMAX = index;

				for (int j = index; j < colMAX; j++) {
					arr[i][j] = 0;
				}
			}
			if (newColMAX > colMAX) colMAX = newColMAX;
		}
		else {
			// C연산 아래쪽으로 쭈욱
			int newRowMAX = 0;
			for (int j = 0; j < colMAX; j++){
				int forMAX = 0;
				for (int i = 0; i < rowMAX; i++) {
					if (arr[i][j] == 0) continue;
					dist[arr[i][j]]++;
					if (arr[i][j] > forMAX) forMAX = arr[i][j];
				}

				for (int i = 1; i <= forMAX; i++) {
					if (dist[i] == 0) continue;
					q.push({ i, dist[i] });
					dist[i] = 0;
				}
				
				int index = 0;
				while (!q.empty()) {
					arr[index++][j] = q.top().val;
					arr[index++][j] = q.top().cnt;
					q.pop();
				}
				if (newRowMAX < index) newRowMAX = index;

				for (int i = index; i < rowMAX; i++) {
					arr[i][j] = 0;
				}
			}
			if (newRowMAX > rowMAX) rowMAX = newRowMAX;

		}

		

		t++;
	}
	//for (int i = 0; i < rowMAX; i++) {
	//	for (int j = 0; j < colMAX; j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	return 0;
}