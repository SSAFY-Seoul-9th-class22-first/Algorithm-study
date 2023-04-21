#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	string inputStr; cin >> inputStr;
	string cmpStr; cin >> cmpStr;
	vector<char> v;
	int cmpLength = cmpStr.size();

	for (int i = 0; i < inputStr.size(); i++) {
		v.push_back(inputStr[i]);
		if (v.size() >= cmpLength) {
			int flag = 0;
			for (int j = 0; j < cmpLength; j++) {
				if (v[v.size() - cmpLength + j] != cmpStr[j]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0 and v.size() > 0) {
				for (int j = 0; j < cmpLength; j++) {
					v.pop_back();
				}
			}
		}
	}

	if (v.size() == 0) cout << "FRULA";
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
	}

	return 0;
}