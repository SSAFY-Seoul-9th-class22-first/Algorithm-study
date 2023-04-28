#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
using psi = pair<string, int>;


vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> map;
	vector<psi> cmds;
	for (int i = 0; i < record.size(); ++i) {
		char cmd[11], name[11], id[11];
		string now = record[i];
		sscanf(now.c_str(), "%s %s %s", cmd, id, name);
		if (strcmp(cmd, "Enter") == 0) {
			map[id] = string(name);
			cmds.push_back({ id, 1 });
		}
		else if (strcmp(cmd, "Leave") == 0) {
			cmds.push_back({ id, 2 });
		}
		else if (strcmp(cmd, "Change") == 0) {
			map[id] = string(name);
		}
	}
	for (int i = 0; i < cmds.size(); ++i) {
		psi now = cmds[i];
		char msg[30];
		if (now.second == 1) sprintf(msg, "%s님이 들어왔습니다.", map[now.first].c_str());
		else if (now.second == 2) sprintf(msg, "%s님이 나갔습니다.", map[now.first].c_str());
		answer.push_back(string(msg));
	}

	return answer;
}
