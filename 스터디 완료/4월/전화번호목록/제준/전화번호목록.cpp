#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N;
vector<string> vec;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			vec.push_back(str);
		}
		sort(vec.begin(), vec.end());

		int flag = 0;
		for (int i = 0; i < vec.size()-1; i++) {
			string now = vec[i];
			string next = vec[i + 1];
			if (now.length() > next.length()) continue;
			if (now == next.substr(0, now.length())) {
				flag = 1;
				break;
			}
		}

		if (flag == 1) cout << "NO" << '\n';
		else cout << "YES" << '\n';

		vec.clear();
	}
}