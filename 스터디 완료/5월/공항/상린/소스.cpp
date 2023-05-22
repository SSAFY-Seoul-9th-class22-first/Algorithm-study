#include <iostream>

using namespace std;

int DAT[1000000];
int main()
{
	int G, P; cin >> G >> P; // G:게이트수 P:비행기수
	int ans = 0, end=0;
	for (int i = 0;i < P;++i)
	{
		int now; cin >> now;
		if (end == 1) continue;
		// 도착한 비행기 도킹하기 - 최대 게이트에 넣기
		int flag = 0;
		for (int j = now;j >= 1;--j)
		{
			if (DAT[j] == 0)
			{
				DAT[j] = 1;
				flag = 1;
				ans++;
				break;
			}
		}
		if (flag == 0) end = 1;
	}
	// 출력 : 도킹 가능한 최대 비행기 수
	cout << ans;
	return 0;
}