#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int strLength = s.size();
    int answer = strLength;
    // i 문자열 길이
    for (int i = 1; i <= strLength / 2; i++) {
        int cnt = 1;
        string a = s.substr(0, i);
        string b = "";
        // i만큼씩 j 증가!
        for (int j = i; j < strLength; j += i) {
            // 비교하는 문자열이 같다면
            if (a == s.substr(j, i)) cnt++;
            else {
                // 다른 구간이 나오기 시작하면
                if (cnt > 1) {
                    // 그 전에 쌓인 개수가 있다면
                    // 개수를 추가
                    b += to_string(cnt);
                }
                b += a;
                // 새로운 비교 문자열 지정
                a = s.substr(j, i);
                // 개수 카운터 초기화
                cnt = 1;
            }
        }
        if (cnt > 1) b += to_string(cnt);
        b += a;
        if (answer > b.size()) answer = b.size();
    }
    return answer;
}