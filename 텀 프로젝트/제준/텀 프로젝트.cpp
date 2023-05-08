#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int visited[101010];
int lovers[101010];
int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;
		for (int j = 1; j <= num; j++) {
			cin >> lovers[j];
		}

		for (int j = 1; j <= num; j++) {
			if (visited[j] != 0) continue;
			vector<int> vec;
			unordered_map<int, int> um;
			vec.push_back(j);
			um.insert({ j, 0 });
			int temp = j;
			while (1) {
				if (temp < j || visited[lovers[temp]] != 0) {
					for (int k = 0; k < vec.size(); k++) {
						visited[vec[k]] = -1;
					}
					break;
				}
				
				if (um.find(lovers[temp]) != um.end()) {
					for (int k = um[lovers[temp]]; k < vec.size(); k++) {
						visited[vec[k]] = 1;
					}
					break;
				}

				temp = lovers[temp];
				um.insert({ temp, vec.size() });
				vec.push_back(temp);
			}
		}

		int cnt = 0;
		for (int j = 1; j <= num; j++) {
			if (visited[j] != 1) cnt++;
		}
		cout << cnt << '\n';

		for (int j = 1; j <= num; j++) {
			visited[j] = 0;
			lovers[j] = 0;
		}
	}
}

