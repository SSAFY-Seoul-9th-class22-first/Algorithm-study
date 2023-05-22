#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
/*
보석 N
무게 M, 가격 V
가방 K개, 최대 무게 C

*/


int N,K;





int main()
{
	long long ans=0;
	cin >> N>>K;

	vector <pair<int, int>> s(N);
	vector<int> b(K);
	for (int i = 0; i < N; i++)
	{
		
		cin >> s[i].first >> s[i].second;
		
	}

	for (int i = 0; i < K; i++)
	{
	
		cin >> b[i];
		
	}

	sort(s.begin(), s.end());
	sort(b.begin(), b.end());

	int i = 0, j = 0;
	priority_queue <int> p;
	/*
	2 99
	1 65
	5 23

	10
	2
	*/


	for (int j = 0; j < b.size(); j++)
	{
		while (i < N && s[i].first <= b[j])
		{
			p.push(s[i++].second);
		}

		if (!p.empty())
		{
			ans += (long long)p.top();
			p.pop();
		}
	}

	cout << ans;
	return 0;
}