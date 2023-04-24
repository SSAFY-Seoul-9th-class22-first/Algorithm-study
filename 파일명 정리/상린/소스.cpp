#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

// 1. HEAD 기준 사전순 정렬 - 대소문자 구분X
// 2. NUMBER의 숫자 순 정렬
// 3. 입력 시의 순서 지켜서

struct File{
    string sa;
    int number;
    string s;
};

bool cmp(File left, File right)
{
    if (left.sa < right.sa) return true;
    if (left.sa > right.sa) return false;
    if (left.number < right.number) return true;
    return false;
}

File f[1000];

vector<string> solution(vector<string> files) {
    vector<string> answer;
    int N = files.size();
    for (int i=0;i<N;i++)
    {
        char ca[100];
        char temp[100];
        sscanf(files[i].c_str(),"%[a-zA-Z-. ]%d%s",ca,&f[i].number,temp);
        f[i].s=files[i];
        f[i].sa=ca;
        // 대문자 변환
        for (int j=0;j<f[i].sa.size();j++)
        {
            if (f[i].sa[j]>='a'&&f[i].sa[j]<='z')
                f[i].sa[j]+=('A'-'a');
        }
        cout << f[i].sa << " " << f[i].number << endl;
    }
    
    stable_sort(f,f+N,cmp);
    
    for (int i=0;i<N;i++)
        answer.push_back(f[i].s);
    
    return answer;
}