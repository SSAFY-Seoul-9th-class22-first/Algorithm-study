#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int cal(int year, int mon, int day){
    return 12*28*year + mon*28 + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int year, mon, day;
    int termss[100];
    sscanf(today.c_str(), "%d.%d.%d", &year, &mon, &day);
    int cmpint1 = cal(year, mon, day);
    for (int i = 0; i<terms.size(); ++i){
            char a; int b;
            sscanf(terms[i].c_str(), "%c %d", &a, &b);
            termss[a] = b;
    }
    for (int i = 0; i<privacies.size(); ++i){
            int y,m,d; char t;
            sscanf(privacies[i].c_str(), "%d.%d.%d %c", &y, &m, &d, &t);
            int cmpint2 = cal(y, m, d);
            if ((cmpint2 + termss[t] * 28) <= cmpint1) answer.push_back(i+1);
    }
    return answer;
}
