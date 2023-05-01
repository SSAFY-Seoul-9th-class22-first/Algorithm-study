#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
	int answer = 0;
	string temp_ans = "";
	int start = 0;
	while (start < s.size()) {
		if (s[start] >= '0' && s[start] <= '9') {
			temp_ans += s[start];
			start++;
		}
		else if (s.find("zero", start) == start) {
			temp_ans += '0';
			start += 4;
		}
		else if (s.find("one", start) == start) {
			temp_ans += '1';
			start += 3;
		}
		else if (s.find("two", start) == start) {
			temp_ans += '2';
			start += 3;
		}
		else if (s.find("three", start) == start) {
			temp_ans += '3';
			start += 5;
		}
		else if (s.find("four", start) == start) {
			temp_ans += '4';
			start += 4;
		}
		else if (s.find("five", start) == start) {
			temp_ans += '5';
			start += 4;
		}
		else if (s.find("six", start) == start) {
			temp_ans += '6';
			start += 3;
		}
		else if (s.find("seven", start) == start) {
			temp_ans += '7';
			start += 5;
		}
		else if (s.find("eight", start) == start) {
			temp_ans += '8';
			start += 5;
		}
		else if (s.find("nine", start) == start) {
			temp_ans += '9';
			start += 4;
		}
	}
	answer = stoi(temp_ans);
	return answer;
}