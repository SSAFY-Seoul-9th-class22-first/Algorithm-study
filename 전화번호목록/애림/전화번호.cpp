#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int T, N;
string s;
vector <string> vs;

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> s;
			vs.push_back(s);
		}

		sort(vs.begin(), vs.end());


		int flag = 0;
		for (int i = 0; i < vs.size() - 1; i++)
		{
			string now = vs[i];
			string next = vs[i + 1];
			if (now.length() > next.length())continue;
			if (now == next.substr(0, now.length()))
			{
				flag = 1;
				break;
			}
		}

		if (flag == 1)
			cout << "NO" << endl;
		else
			cout << "YES\n";

		vs.clear();
	}
	return 0;
}