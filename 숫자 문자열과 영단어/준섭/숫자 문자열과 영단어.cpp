#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string str ="";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9'){
            str += s[i];
        }
        else if (s[i] == 'z') {
            str += "0";
            i += 3;
        }
        else if (s[i] == 'o') {
            str += "1";
            i += 2;
        }
        else if (s[i] == 't') {
            if (s[i + 1] == 'w') {
                str += "2";
                i += 2;
            }
            else if (s[i + 1] == 'h'){
                str += "3";
                i += 4;
            }
        }
        else if (s[i] == 'f') {
            if (s[i + 1] =='o') {
                str += "4";
                i += 3;
            }
            else if (s[i + 1] == 'i') {
                str += "5";
                i += 3;
            }
        }
        else if (s[i] == 's') {
            if (s[i + 1] == 'i') {
                str += "6";
                i += 2;
            }
            else if (s[i + 1] == 'e') {
                str += "7";
                i += 4;
            }
        }
        else if (s[i] == 'e') {
            str += "8";
            i += 4;
        }
        else if (s[i] == 'n') {
            str += "9";
            i += 3;
        }
    }
    int answer = stoi(str);
    return answer;
}