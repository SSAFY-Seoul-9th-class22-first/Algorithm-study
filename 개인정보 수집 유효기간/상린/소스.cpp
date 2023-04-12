#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Date{
    int year,mon,day;
};

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer; // idx 1부터 시작
    
    // map에 type과 기간 저장
    unordered_map<char,int> um;
    for (int i=0;i<terms.size();i++)
        um[terms[i][0]]=stoi(terms[i].substr(2,terms[i].size()-2));
    
    // today판별
    Date Dtoday = {stoi(today.substr(0,4)),stoi(today.substr(5,2)),stoi(today.substr(8,2))};
    
    for (int i=0;i<privacies.size();i++)
    {
        // 만료 기간이 언제인지 판별
        Date end = {stoi(privacies[i].substr(0,4)),stoi(privacies[i].substr(5,2)),stoi(privacies[i].substr(8,2))};
        
        end.mon+=um[privacies[i][11]];
        
        if (end.mon>12)
        {
            int offset = end.mon/12;
            end.mon-=(12*offset);
            end.year+=offset;
            if (end.mon==0)
            {
                end.mon=12;
                end.year--;
            }
        }
        
        // 만료 기간이 지났는지 판별 - 지난 것을 저장
        if (end.year>Dtoday.year) continue;
        else if (end.year<Dtoday.year) answer.push_back(i+1);  
        else
        {
            // 년도 같을 때
            if (end.mon>Dtoday.mon) continue;
            else if (end.mon<Dtoday.mon) answer.push_back(i+1);
            else
            {
                // 달 같을 때
                if (end.day<=Dtoday.day) answer.push_back(i+1);
            }
        }
        
    }
    
    return answer;
}