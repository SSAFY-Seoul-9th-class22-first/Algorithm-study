#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1;
	cin >> str2;
	while (1) {
		if (str1.find(str2) == string::npos) break;
		str1.erase(str1.find(str2), str2.length());
	}

	if (str1 == "") cout << "FRULA";
	else cout << str1;
}