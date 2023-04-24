#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct file{
    string head;
    int num, idx;
};

file name2file(string str, int idx){
    int flag = 0, num;
    string head, number;
    for (int i = 0; i < str.size(); ++i) {
        if (isdigit(str[i])) {
            flag = 1;
            number += str[i];
        }
        else {
            if (flag) break;
            head += tolower(str[i]);
        }
    }
    num = stoi(number);
    
    return {head, num, idx};
}

bool cmp(file a, file b){
    if (a.head != b.head) return a.head < b.head;
    if (a.num != b.num) return a.num < b.num;
    return a.idx < b.idx;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<file> formatFiles;

    for (int i = 0 ; i < files.size(); ++i){
        file now = name2file(files[i],i);
        formatFiles.push_back(now);
        //cout << now.head << " "  << now.num << " "  << now.idx << "\n";
    }
    sort(formatFiles.begin(), formatFiles.end(), cmp);
    for (int i = 0 ; i < files.size(); ++i){
        answer.push_back(files[formatFiles[i].idx]);
    }
    
    return answer;
}
