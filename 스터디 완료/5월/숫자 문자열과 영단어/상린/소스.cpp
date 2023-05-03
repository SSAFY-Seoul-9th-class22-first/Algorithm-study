#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    int answer = 0;
    unordered_map<string,int> um;
    string nums[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    for (int i=0;i<10;i++) um[nums[i]]=i;
    string sn = "";
    for (int i=0;i<s.size();i++)
    {
        if (s[i]>='0'&&s[i]<='9') answer = answer*10 + (s[i]-'0');
        else
        {
            sn+=s[i];
            if (um.find(sn)!=um.end())
            {
                answer=answer*10+um[sn];
                sn="";
            }
        }
    }
    if (sn!="") answer = answer*10 + um[sn];
     
    return answer;
}