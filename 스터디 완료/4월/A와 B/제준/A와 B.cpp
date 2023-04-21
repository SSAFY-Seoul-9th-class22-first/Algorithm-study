#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	if (str1.size() > str2.size()) {
		string temp = str1;
		str1 = str2;
		str2 = temp;
	}
	while (str1.size() < str2.size()) {
		if (str2[str2.size() - 1] == 'A') {
			str2.erase(str2.end() - 1);
		}
		else if (str2[str2.size() - 1] == 'B') {
			str2.erase(str2.end() - 1);
			reverse(str2.begin(), str2.end());
		}
	}

	if (str1 == str2) cout << 1;
	else cout << 0;
}