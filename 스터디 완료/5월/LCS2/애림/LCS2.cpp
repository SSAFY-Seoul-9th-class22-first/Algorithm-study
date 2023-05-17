#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string a, b;
int dp[1001][1001];

int main()
{
	cin >> a >> b;

	int aSize = a.length();
	int bSize = b.length();
	string ans = "";
	for (int i = 1; i <= aSize; i++)
	{
		for (int j = 1; j <= bSize; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;


			}

			
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}


	cout << dp[aSize][bSize]<<"\n";


	int i = aSize ;
	int j = bSize ;


	while (i !=0 || j !=0)
	{

		if( i&&j && a[i-1]==b[j-1])
		{
			ans += a[i-1];
			i--;
			j--;
		}
		else if (j&& dp[i][j] == dp[i][j - 1])
			j--;
		else
			i--;
		
		
	}

	/*
*
  A C A Y K P
0 0 0 0 0 0 0
C 0 1 1 1 1 1
A 1 1 2 2 2 2
P 1 1 2 2 2 3
C 1 2 2 2 2 3
A 1 2 3 3 3 3
K 1 2 3 3 4 4

*/
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}

