#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	string s, t;
	cin >> s >> t;

	while (1) {
		if (s.size() == t.size()) {
			if (s == t) {
				cout << 1;
				return 0;
			}
			else {
				cout << 0;
				return 0;
			}
		}

		if (t[t.size() - 1] == 'A') {
			t.pop_back();
		}
		else {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}
	return 0;
}