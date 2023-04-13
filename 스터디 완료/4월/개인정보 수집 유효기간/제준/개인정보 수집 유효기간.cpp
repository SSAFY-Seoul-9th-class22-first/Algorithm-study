#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;

	for (int i = 1; i <= privacies.size(); i++) {
		string temp = privacies[i - 1];
		char alphabet = privacies[i - 1][temp.size() - 1];
		int term_index = 0;
		for (int j = 0; j < terms.size(); j++) {
			if (terms[j][0] == alphabet) {
				term_index = j;
				break;
			}
		}
		int months = 0;
		if (terms[term_index].size() == 3) {
			months = terms[term_index][2] - '0';
		}

		else if (terms[term_index].size() == 4) {
			months = (terms[term_index][2] - '0') * 10 + (terms[term_index][3] - '0');
		}

		else if (terms[term_index].size() == 5) {
			months = (terms[term_index][2] - '0') * 100 + (terms[term_index][3] - '0') * 10 + (terms[term_index][4] - '0');
		}

		int y = 0;
		int m = 0;
		int d = 0;
		for (int j = 0; j < 4; j++) {
			y += (temp[j] - '0') * pow(10, 3 - j);
		}
		for (int j = 5; j < 7; j++) {
			m += (temp[j] - '0') * pow(10, 6 - j);
		}
		for (int j = 8; j < 10; j++) {
			d += (temp[j] - '0') * pow(10, 9 - j);
		}
		d--;
		if (d == 0) {
			m--;
			d = 28;
		}
		m += months;
		if (m > 12) {
			m--;
			y += (m / 12);
			m %= 12;
			m++;
		}


		int comp_y = 0;
		int comp_m = 0;
		int comp_d = 0;
		for (int j = 0; j < 4; j++) {
			comp_y += (today[j] - '0') * pow(10, 3 - j);
		}
		for (int j = 5; j < 7; j++) {
			comp_m += (today[j] - '0') * pow(10, 6 - j);
		}
		for (int j = 8; j < 10; j++) {
			comp_d += (today[j] - '0') * pow(10, 9 - j);
		}

		if (y < comp_y) answer.push_back(i);
		else if (y == comp_y) {
			if (m < comp_m) answer.push_back(i);
			else if (m == comp_m) {
				if (d < comp_d) answer.push_back(i);
			}
		}

	}

	return answer;
}