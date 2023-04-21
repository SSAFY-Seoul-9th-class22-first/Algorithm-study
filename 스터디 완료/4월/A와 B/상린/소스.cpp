#include <iostream>
#include <string>

using namespace std;

int main()
{
	string S, T;
	cin >> S >> T;
	
	while (S.size() < T.size())
	{
		if (T[T.size() - 1] == 'B') // 뒤집기
		{
			T = T.substr(0, T.size() - 1);
			int len = T.size();
			for (int i = 0;i < len / 2;i++)
			{
				char temp = T[i];
				T[i] = T[len - 1 - i];
				T[len - 1 - i] = temp;
			}
		}
		else T = T.substr(0, T.size() - 1);
	}
	
	if (S == T) cout << 1;
	else cout << 0;

	return 0;
}