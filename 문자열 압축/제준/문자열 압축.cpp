#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int solution(string s) {
	int answer = s.size();
	for (int i = 1; i <= s.size() / 2; i++) {
		int str_size = s.size();
		int start = 0;

		while (start + i <= s.size()) {
			string temp = s.substr(start, i);
			start += i;

			int cnt = 1;
			while (start + i <= s.size()) {
				if (temp == s.substr(start, i)) {
					cnt++;
					start += i;
				}
				else break;
			}
			if (cnt < 10 && cnt > 1) {
				str_size -= cnt * i;
				str_size += i;
				str_size += 1;
			}
			else if (cnt >= 10 && cnt < 100) {
				str_size -= cnt * i;
				str_size += i;
				str_size += 2;
			}
			else if (cnt >= 100 && cnt < 1000) {
				str_size -= cnt * i;
				str_size += i;
				str_size += 3;
			}
			else if (cnt == 1000) {
				str_size -= cnt * i;
				str_size += i;
				str_size += 4;
			}


			answer = min(answer, str_size);
		}
	}

	return answer;
}