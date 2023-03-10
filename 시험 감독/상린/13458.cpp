#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int N; cin >> N; // N ������ ����
	int arr[1000000];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int B, C; cin >> B >> C; // B,C

	// �Ѱ��� 1�� �ΰ��� ������ -> �ʿ��� ������ ��

	// ��� �������� ����
	long long ans = 0;

	// ��� �����忡 ������ ��ġ�ϱ�
	for (int i = 0; i < N; i++)
	{
		arr[i] -= B; // �Ѱ��� ��ġ
		ans++;
		if (arr[i] <= 0) continue;

		// �ΰ��� ��ġ
		ans += arr[i] / C;
		if (arr[i] % C != 0) ans++;
	}

	cout << ans;

	return 0;
}