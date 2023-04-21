#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;
string in;
string bomb;

int main()
{
	cin >> in;
	cin >> bomb;
	int bomb_len = bomb.length();
	int idx = 0;
	string s;
	for(int i=0;i<in.length();i++)
	{
		s += in[i];
		if (s.length() >= bomb_len)
		{
			bool flag = true;
			for (int j = 0; j < bomb_len; j++)
			{

				if (s[s.length() - bomb_len + j] != bomb[j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
				s.erase(s.length() - bomb_len, bomb_len);
		}
	

	}

	//cout << in;
	if (s.size() == 0)
		cout << "FRULA";
	else
		cout << s;
}