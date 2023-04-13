#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int N; cin >> N; // N 시험장 개수
	int arr[1000000];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int B, C; cin >> B >> C; // B,C

	// 총감동 1명 부감동 여러명 -> 필요한 감독관 수

	// 모든 시험장을 돌기
	long long ans = 0;

	// 모든 시험장에 감독관 배치하기
	for (int i = 0; i < N; i++)
	{
		arr[i] -= B; // 총감독 배치
		ans++;
		if (arr[i] <= 0) continue;

		// 부감독 배치
		ans += arr[i] / C;
		if (arr[i] % C != 0) ans++;
	}

	cout << ans;

	return 0;
}