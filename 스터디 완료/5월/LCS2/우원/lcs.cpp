#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1010][1010];
int n, m;
string a, b;
string ans;

int main() {
    cin >> a >> b;
    n = a.size();
    m = b.size();
    for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) {
        if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }

    for (int i=n, j=m; i!=0 || j!=0; ) {
        if (i && j && a[i-1] == b[j-1]) {
            ans += a[i-1];
            i--, j--;
        } else if (j && dp[i][j] == dp[i][j-1]) j--; 
        else i--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n' << ans;
}
