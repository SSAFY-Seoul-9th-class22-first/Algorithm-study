#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> um;
	vector<pair<string, int>> todo_list;

	for (int i = 0; i < record.size(); i++) {
		int index = record[i].find("uid") + 3;
		string id = "";
		while (record[i][index] != ' ' && index < record[i].size()) {
			id += record[i][index];
			index++;
		}

		if (record[i][0] == 'L') {
			todo_list.push_back({ id, 0 });
			continue;
		}
		index++;
		string nickname = "";
		while (index < record[i].size()) {
			nickname += record[i][index];
			index++;
		}

		if (record[i][0] == 'E') {
			if (um.find(id) != um.end()) {
				if (nickname != um[id]) um[id] = nickname;
			}
			else {
				um.insert({ id, nickname });
			}
			todo_list.push_back({ id, 1 });
		}

		else if (record[i][0] == 'C') {
			um[id] = nickname;
		}
	}

	for (int i = 0; i < todo_list.size(); i++) {
		if (todo_list[i].second == 0) {
			answer.push_back(um[todo_list[i].first] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		}
		else {
			answer.push_back(um[todo_list[i].first] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		}
	}

	return answer;
}

int main() {
	vector<string> str = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };
	vector<string> ans = solution(str);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}