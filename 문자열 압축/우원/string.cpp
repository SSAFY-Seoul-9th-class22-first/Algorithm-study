#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int ans = s.size();
    int sz = s.size();
    for (int subsz = 1; subsz<=sz/2; ++subsz){
        int cnt = 1; int tmp = 0;
        string str = s.substr(0,subsz);
        for (int idx = subsz; idx < sz; idx+=subsz){
            if (str==s.substr(idx,subsz)) cnt++;
            else {
                if (cnt > 1) tmp += to_string(cnt).size();
                tmp += subsz; cnt = 1;
                str = s.substr(idx,subsz);
            }
        }
        if (cnt > 1) tmp += to_string(cnt).size();
        tmp += str.size();
        ans = min(ans,tmp);

    }
    return ans;
}
