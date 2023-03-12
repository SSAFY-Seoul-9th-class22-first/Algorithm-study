#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>


using namespace std;
using piii = tuple<int, int, int>;
using pii = pair<int, int>;

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        vector<int> arr(n);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            mx = max(mx, arr[i]);
        }

        int cnt[3] = { 0, };
        // cnt -> 홀수임짝수임? 
        // cnt[0] 짝수 개수 cnt[1] 홀수 개수
        // 맥스랑 차가 홀수냐 짝수냐를 확인하는거지
        for (int i = 0; i < n; ++i) {
            arr[i] = mx - arr[i];
            // bit연산자깐 0000001 이랑 앤드연산 홀수면 1 총 홀수인애들이랑 짝수인애들 세는 작업
            cnt[arr[i] & 1]++;
            // cnt[2] 비트연산 나누기 2의 몫 (총 몇번해야할까를 확인하는 작업)
            cnt[2] += arr[i] >> 1;
        }
        
        // 짝수애들 홀수에다가 몰아주기(2초단위로 맞추는거지)
        while (cnt[1] < cnt[2] - 1) {
            cnt[2]--;
            cnt[1] += 2;
        }
        int ans = 0;
        // 두개 같으면 한세트로 cnt[1]번 만큼이니깐 곱하기 2
        if (cnt[1] == cnt[2]) {
            ans = cnt[1] * 2;
        }
        // 홀수가 하나 더 많으면은 한번 덜해도됨(위에꺼에 비해서 )
        else if (cnt[1] == cnt[2] + 1) {
            ans = cnt[2] * 2 + 1;
        }
        // 짝수가 하나 더 많으면
        else if (cnt[1] + 1 == cnt[2]) {
            ans = cnt[2] * 2;
        }
        else {
            ans = (cnt[1] - 1) * 2 + 1;
        }
        cout << '#' << t << ' ' << ans << endl;
    }
}
