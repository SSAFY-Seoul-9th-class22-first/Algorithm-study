#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> saveStr;
    vector<int> flag;
    map<string, string> m;
    char entrance[11], userID[11], name[11];
    for (int i = 0; i < record.size(); i++) {
        
        if (record[i][0] == 'E') {
            // 입장
            sscanf(record[i].c_str(), "%s %s %s", entrance, userID, name);
            if (m.find(userID) != m.end()) {
                // 있으면
                m[userID] = name;
                saveStr.push_back(userID);
                flag.push_back(1);
            }
            else {
                // 없으면
                m.insert({userID, name});
                saveStr.push_back(userID);
                flag.push_back(1);
            }
        }
        else if (record[i][0] == 'L') {
            // 퇴장
            sscanf(record[i].c_str(), "%s %s", entrance, userID);
            saveStr.push_back(userID);
            flag.push_back(0);
            
        }
        else if (record[i][0] == 'C'){
            // 닉네임 변환
            sscanf(record[i].c_str(), "%s %s %s", entrance, userID, name);
            m[userID] = name;
        }
    }
    for (int i = 0; i < saveStr.size(); i++) {
        if (flag[i] == 1) {
            // 입장
            string as = m[saveStr[i]];
            as += "님이 들어왔습니다.";
            answer.push_back(as);
        }
        else {
            // 퇴장
            string as = m[saveStr[i]];
            as += "님이 나갔습니다.";
            answer.push_back(as);
        }
    }
    return answer;
}