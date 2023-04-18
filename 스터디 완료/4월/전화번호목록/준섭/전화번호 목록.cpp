#include <iostream>
#include <string>
#include <deque>
#include <algorithm>


using namespace std;

int main() {

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		deque<string> dq;
		int flag = 0;
		for (int N = 0; N < n; N++) {
			string str; cin >> str;
			dq.push_back(str);
		}
		
		sort(dq.begin(), dq.end());
		for (int i = 0; i < dq.size() - 1; i++) {
			// 두 문자열의 크기가 같으면 다른 번호, 
			// 현재 문자열의 크기가 다음 크기보다 같으면 다른 번호
			if (dq[i].size() >= dq[i + 1].size()) continue;

			// 다음 문자열의 현재 문자열 사이즈만큼이 동일하다면 떙!
			if (dq[i + 1].substr(0, dq[i].size()) == dq[i]) {
				cout << "NO\n";
				flag = 1;
				break;
			}
		}
		if (!flag) cout << "YES\n";
		
	}

	return 0;
}