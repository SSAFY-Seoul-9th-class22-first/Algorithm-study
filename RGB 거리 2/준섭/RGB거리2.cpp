#include <iostream>

using namespace std;

int rgbCost[1010][3];

int main() {

	int n;
	int ans = 987654321;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> rgbCost[i][0] >> rgbCost[i][1] >> rgbCost[i][2];
	}
	// 아오 디피 개짜증나네;
	for (int i{}; i < 3; i++) {
		int dp[1010][3];
		for (int j{}; j < 3; j++) {
			if (i == j) dp[1][i] = rgbCost[1][i];
			else dp[1][j] = 987654321;
		}  

		// r 이면 전 g, b
		for (int j = 2; j <= n; j++) {
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + rgbCost[j][0];
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + rgbCost[j][1];
			dp[j][2] = min(dp[j - 1][1], dp[j - 1][0]) + rgbCost[j][2];
		}

		for (int j{}; j < 3; j++) {
			// 만약 시작이랑 끝이 같으면 패스
			if (i == j) continue;
			ans = min(ans, dp[n][j]);
		}
	}
	cout << ans;
	return 0;
}