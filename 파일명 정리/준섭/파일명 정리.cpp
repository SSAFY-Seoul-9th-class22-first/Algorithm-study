#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    string HEAD = "";
    string HEAD_CHANGE = "";
    string num1 = "";
    int num2 = 0;
    string TAIL = "";
    int count;
};

bool cmp(node left, node right){
    if (left.HEAD_CHANGE > right.HEAD_CHANGE) return false;
    if (left.HEAD_CHANGE < right.HEAD_CHANGE) return true;
    if (left.num2 > right.num2) return false;
    if (left.num2 < right.num2) return true;
    if (left.count > right.count) return false;
    if (left.count < right.count) return true;
    return false; 
}

vector<node> v;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    for (int i = 0; i < files.size(); i++) {
        int flag = 0;
        node input;
        input.count = i;
        for (int j = 0; j < files[i].size(); j++) {
            if (flag == 2) {
                input.TAIL += files[i][j];
                continue;
            }
            
            if (flag == 1 and !(files[i][j] >= '0' and files[i][j] <= '9')){
                flag = 2;
                input.TAIL += files[i][j];
                continue;
            }
            
            if (files[i][j] >= '0' and files[i][j] <= '9' and (flag == 0 or flag == 1)) {
                flag = 1;
                input.num1 += files[i][j];
                continue;
            }
            
            if (flag == 0) {
                input.HEAD += files[i][j];
                if (files[i][j] >= 'A' and files[i][j] <= 'Z'){
                    char c = files[i][j] + 32;
                    input.HEAD_CHANGE += c;
                }
                else input.HEAD_CHANGE += files[i][j];
            }
        }
        input.num2 = stoi(input.num1);
        v.push_back(input);
        //cout << input.HEAD << " " << input.num2 << " " << input.TAIL << endl;
    }
    
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        string str = v[i].HEAD + v[i].num1 + v[i].TAIL;
        answer.push_back(str);
    }
    
    return answer;
}