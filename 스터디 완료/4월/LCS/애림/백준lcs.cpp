#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string a, b;
int dp[1001][1001];

int main()
{
	cin >> a >> b;

	int aSize = a.length();
	int bSize = b.length();

	for (int i = 1; i <= aSize; i++)
	{
		for (int j = 1; j <= bSize; j++)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	cout << dp[aSize][bSize];
	return 0;
}