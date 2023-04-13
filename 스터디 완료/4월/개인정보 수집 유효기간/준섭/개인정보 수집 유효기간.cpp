#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    int year = stoi(today.substr(0, 4));
    int mon = stoi(today.substr(5, 2));
    int day = stoi(today.substr(8, 2));
    int termsArr[91] = {0};
    vector<int> answer;
    
    for (int i = 0; i < terms.size(); i++) {
        termsArr[(char)terms[i][0]] = stoi(terms[i].substr(2));
    }
    
    for (int i = 0; i < privacies.size(); i++) {
        int y, m, d, t;
        y = stoi(privacies[i].substr(0, 4));
        m = stoi(privacies[i].substr(5, 2));
        d = stoi(privacies[i].substr(8, 2));
        t = termsArr[(char)privacies[i][11]];
        
        if (y == year) {
            if (mon - m > t) {
                answer.push_back(i + 1);
                continue;
            }
            else if (mon - m == t) {
                if (d <= day) {
                    answer.push_back(i + 1);
                    continue;
                }
            }
        }
        else {
            int cmpM = ((12 - m) + mon) + ((year - y)-1)*12;
            if (cmpM > t) {
                answer.push_back(i + 1);
                continue;
            }
            else if (cmpM == t) {
                if (d <= day) {
                    answer.push_back(i + 1);
                    continue;
                }
            }
            
        }
    }
    
    return answer;
}