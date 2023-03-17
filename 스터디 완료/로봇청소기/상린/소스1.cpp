#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int N, M; cin >> N >> M;

	int y, x, d; cin >> y >> x >> d;
	// d : 0�� 1�� 2�� 3��

	int Dr[2][4] = {
		-1,0,1,0,
		0,1,0,-1,
	};

	int MAP[50][50];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j]; // 0û��X��ĭ 1�� -1û��O��ĭ
		}
	}

	// û�ұ� �۵��ϱ�
	int ans = 0;
	while (1)
	{
		// 1. ���� ĭ û���ϱ�
		if (MAP[y][x] == 0)
		{
			ans++;
			MAP[y][x] = -1;
		}

		// 1. �ݽð�� ȸ���ϱ�

		int flag = 0;
		for (int i = 1; i <= 4; i++)
		{
			// û�ҵ��� ���� ��ĭ ã��
			int nd = d - i;
			if (nd < 0) nd += 4;

			int ny = y + Dr[0][nd];
			int nx = x + Dr[1][nd];
			if (MAP[ny][nx] == 0)
			{
				y = ny;
				x = nx;
				d = nd;
				flag = 1;
				break;
			}
		}

		if (flag) continue; // û���� ��ĭ ã�Ҵٸ� �ٽ� 1���� ����

		// �ٶ󺸴� ������ ������ä�� ��ĭ �����ϰ� 1������ ���ư���
		int by = y - Dr[0][d];
		int bx = x - Dr[1][d];

		// ���̶�� �۵� ���߱�
		if (by < 0 || by >= N || bx < 0 || bx >= M) break;
		if (MAP[by][bx] == 1) break;

		y = by; x = bx;
	}

	// ��� : û���ϴ� ĭ�� ����
	cout << ans;

	return 0;
}