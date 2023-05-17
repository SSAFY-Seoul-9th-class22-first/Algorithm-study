#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1010][1010];

int main() {
	string str1;
	string str2;
	cin >> str1 >> str2;
	int n = str1.length();
	int m = str2.length();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	string ans;
	for (int i = n, j = m; i != 0 || j != 0;) {
		if (i && j && str1[i - 1] == str2[j - 1]) {
			ans += str1[i - 1];
			i--;
			j--;
		}
		else if (i && dp[i][j] == dp[i - 1][j]) i--;
		else if (j && dp[i][j] == dp[i][j - 1]) j--;
	}

	reverse(ans.begin(), ans.end());

	cout << dp[n][m] << '\n' << ans;
}