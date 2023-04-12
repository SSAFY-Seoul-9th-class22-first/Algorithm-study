#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1010][1010];

int main() {
	string str1;
	string str2;
	cin >> str1 >> str2;
	int flag1 = 0;
	for (int i = 0; i < str1.length(); i++) {
		if (flag1 == 1) {
			dp[i][0] = 1;
			continue;
		}
		if (str1[i] != str2[0]) dp[i][0] = 0;
		else {
			dp[i][0] = 1;
			flag1 = 1;
		}
	}

	int flag2 = 0;
	for (int i = 0; i < str2.length(); i++) {
		if (flag2 == 1) {
			dp[0][i] = 1;
			continue;
		}
		if (str1[0] != str2[i]) dp[0][i] = 0;
		else {
			dp[0][i] = 1;
			flag2 = 1;
		}
	}

	for (int i = 1; i < str1.length(); i++) {
		for (int j = 1; j < str2.length(); j++) {
			if (str1[i] == str2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[str1.length() - 1][str2.length() - 1];
}