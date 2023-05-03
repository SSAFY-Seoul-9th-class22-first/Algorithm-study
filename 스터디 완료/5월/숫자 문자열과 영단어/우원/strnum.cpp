#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
	unordered_map<string, int> map;
	string answer;
	map["zero"] = 0;
	map["one"] = 1;
	map["two"] = 2;
	map["three"] = 3;
	map["four"] = 4;
	map["five"] = 5;
	map["six"] = 6;
	map["seven"] = 7;
	map["eight"] = 8;
	map["nine"] = 9;
	string tmp;
	for (int i = 0; i < s.size(); ++i) {
		if ('0'<=s[i]&& s[i]<= '9') {
			answer += s[i];
			continue;
		}
		tmp += s[i];
		if (map.find(tmp) != map.end()) {
			answer += to_string(map[tmp]);
			tmp.clear();
		}
	}
	int ret = stoi(answer);
	return ret;
}
