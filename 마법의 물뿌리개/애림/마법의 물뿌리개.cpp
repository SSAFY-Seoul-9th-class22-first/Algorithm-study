#include <iostream>
#include <vector>
using namespace std;

int N;
int tree[101];
int mx;
int min_day;

void solution()
{
	int num1 = 0, num2 = 0;
	int day = 0;
	for (int i = 0; i < N; i++)
	{
		num1 += (mx-tree[i]) / 2;
		num2 += (mx-tree[i]) % 2;
	}

	while (num1>=0)
	{
		if (num1 >= num2)
		{
			day= num1 * 2;
			min_day = min(day, min_day);
		}
		else {
			day = num2*2-1;
			min_day = min(day, min_day);
		}

	//	cout << min_day << endl;
		num1--;
		num2 += 2;
	}
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> tree[i];
		mx = -21e8;
		for (int i = 0; i < N; i++)
			mx = max(tree[i], mx);

		min_day = 21e8;
		
		solution();

		cout << "#" << tc << " " << min_day << endl;
	}
	return 0;
}