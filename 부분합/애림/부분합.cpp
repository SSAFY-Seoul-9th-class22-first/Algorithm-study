#include <iostream>
#include <vector>

using namespace std;
int N,S;
vector <int> v;
int main()
{
	cin >> N;
	cin >> S;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	int p1=0, p2=0;
	int sum = 0;
	int ans = 21e8;

	while(p1<=p2)
	{
		if (sum >= S)
		{
			int len = p2 - p1;
			ans = min(ans, len);
			
			sum -= v[p1];
			p1++;
			continue;
		}
		if (p2 == N)
			break;
		
		sum += v[p2];
		p2++;
	}

	if (ans == 21e8)
		cout << 0;
	else
		cout << ans;
	return 0;
}