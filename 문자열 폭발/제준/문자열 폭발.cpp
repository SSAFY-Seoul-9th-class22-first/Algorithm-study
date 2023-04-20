#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	vector<char> vec;
	for (int i = 0; i < str1.size(); i++) {
		vec.push_back(str1[i]);
		if (vec.size() < str2.size()) continue;
		int flag = 0;
		for (int j = 0; j < str2.size(); j++) {
			if (vec[vec.size() - str2.size() + j] != str2[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			for (int j = 0; j < str2.size(); j++) vec.pop_back();
		}
	}

	if (vec.size() == 0) cout << "FRULA";
	else {
		for (int i = 0; i < vec.size(); i++) {
			cout << (char)vec[i];
		}
	}
}