#include <iostream>

using namespace std;

int main()
{
	int N, S; cin >> N >> S;
	int arr[100000];
	for (int i = 0;i < N;i++)
	{
		cin >> arr[i];
	}

	int left = 0, right = 0, sum=arr[0];
	int ans = -1;
	while (right<N)
	{
		//cout << left << " " << right << " " << sum << endl;
		if (sum < S && (ans == -1 || right - left < ans))
		{
			//cout << "d" << endl;
			right++;
			sum += arr[right];
		}
		else
		{
			if (sum >= S)
			{
				ans = right - left;
				if (left == right||sum<N)
				{
					right++;
					sum += arr[right];
				}
				else
				{
					sum -= arr[left];
					left++;
				}
			}
			else
			{
				right++;
				sum = sum - arr[left] + arr[right];
				left++;
			}
		}
	}

	cout << ans+1;

	return 0;
}