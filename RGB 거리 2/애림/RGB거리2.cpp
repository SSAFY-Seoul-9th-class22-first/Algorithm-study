#include <iostream>
#include <vector>

using namespace std;



int N;

int dp[1001][3];
int v[1001][3];
/*
1번 집의 색은 2번, N번 집의 색과 같지 않아야한다.
N번 집의 색은 N-1번 1번 집의 색과 같지 않아야한다.
i(2<=i<=N-1)번 집의 색은 i-1,i+1번 집의 색과 같지 않아야한다.
*/
int main()
{

	cin >> N;


	int ans = 21e8;
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}

	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (k == i)
				dp[1][i] = v[1][i];
			else
				dp[1][i] = 21e8;
		}

		for (int i = 2; i <= N; i++)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][2];
		}

		for (int i = 0; i < 3; i++)
		{
			if (i != k)
				ans = min(ans, dp[N][i]);
		}
		
	}

	cout << ans;
	return 0;
}