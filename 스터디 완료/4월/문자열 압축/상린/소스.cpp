#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 21e8;
    // 문자열은 같은 단위로, 제일 앞부터 정해진 길이만큼 잘라야함
    int n=0;
    while (n<=s.size()/2) // 언제 탈출해?
    {
        n++; // n길이만큼 자르기
        int temp=0; // 잘랐을 때의 길이
        int stack=1;
        for (int i=n;i<s.size();i+=n)
        {
            if (s.substr(i,n)==s.substr(i-n,n)) stack++;
            else 
            {
                temp+=n;
                if (stack>1) temp+=to_string(stack).size();
                stack=1;
            }
        }
        // 마지막 처리 - 남은 단어들
        // 나눠떨어지지 않을 때
        if (s.size()%n==0)
        {
            temp+=n;
            if (stack>1) temp+=to_string(stack).size();
        }
        else temp+=(s.size()%n);
        answer=min(answer,temp);
    }
    return answer;
}