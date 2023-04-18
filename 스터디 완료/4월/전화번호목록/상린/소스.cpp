#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n; cin >> n;
		string arr[10000];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		string flag = "YES";
		for (int i = 0; i < n-1; i++)
		{
			if (arr[i + 1].length() <= arr[i].length()) continue;
			if (arr[i]==arr[i+1].substr(0,arr[i].length())) // 접두사
			{
				flag = "NO";
				break;
			}
		}

		cout << flag << endl;
	}

	return 0;
}