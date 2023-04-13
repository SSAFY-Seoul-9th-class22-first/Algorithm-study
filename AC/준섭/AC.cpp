#include <iostream>
#include <string>
#include <deque>
#include <sstream>

using namespace std;

int main() {

	int T; cin >> T;
	while (T--) {
		string p; cin >> p;
		
		int n; cin >> n;
		
		string str; cin >> str;
		if (n == 0) str = "";
		else {
			str = str.substr(1, str.size()-2);
		}
		
		deque<string> words;

		stringstream ss(str);

		string word;
		while (getline(ss, word, ',')) {
			words.push_back(word);
		}

		int Rflag = 0;
		int flag = 0;
		for (int pcnt = 0; pcnt < p.size(); pcnt++) {
			if (p[pcnt] == 'R') {
				if (Rflag) Rflag = 0;
				else Rflag = 1;
			}
			else {
				if (words.size() == 0) {
					cout << "error\n";
					flag = 1;
					break;
				}
				
				if (Rflag == 0) {
					// 앞에 제거
					words.pop_front();
				}
				else {
					// 뒤에 제거
					words.pop_back();
				}
			}
		}
		
		if (!flag) {
			cout << "[";
			if (Rflag) {
				//역순 출력
				for (int i = words.size() - 1; i >= 0; i--) {
					cout << words[i];
					if (i != 0) {
						cout << ",";
					}
				}
			}
			else {
				// 원래 방향 출력
				for (int i = 0; i < words.size(); i++) {
					cout << words[i];
					if (i != words.size() - 1) {
						cout << ",";
					}
				}
			}
			cout << "]\n";
		}
		
	}
	return 0;
}