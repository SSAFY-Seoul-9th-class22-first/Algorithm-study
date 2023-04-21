#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s, t;

	cin >> s;
	cin >> t;
	int flag = 0;
	while (s.length() <= t.length())
	{
		if (s.compare(t) == 0)
		{
			cout << 1;
			flag = 1;
			break;
		}

		if (t[t.length() - 1] == 'A')
			t=t.substr(0, t.length() - 1);
		else
		{
			t = t.substr(0, t.length() - 1);
			reverse(t.begin(), t.end());
		}
	}

	if (flag == 0)
		cout << 0;
	return 0;
}