#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>

using namespace std;

struct node{
    string id;
    bool state; // true enter, false leave
};

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    unordered_map<string,string> um;
    vector<node> rst;
    for (int i=0;i<record.size();i++)
    {
        stringstream ss(record[i]);
        string words[3];
        int n=0;
        while (ss >> words[n]) n++; // 공백 파싱
        
        if (words[0]=="Leave") rst.push_back({words[1],false});
        else
        {
            um[words[1]]=words[2];
            if (words[0]=="Enter") rst.push_back({words[1],true});
        }
    }
    
    for (int i=0;i<rst.size();i++)
    {
        answer.push_back(um[rst[i].id]);
        if (rst[i].state) answer[i]+="님이 들어왔습니다."; // enter
        else answer[i]+="님이 나갔습니다.";
    }
    
    return answer;
}