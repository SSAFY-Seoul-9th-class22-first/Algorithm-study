#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

/*
��ĭ -> û��

1. �ֺ� ��ĭ �� û�ҵ��� ���� ��ĭ�� �ִٸ�
�ݽð�������� ȸ�� -> -1 -1�̵Ǹ� 3 -> �����ؼ� û��
2. �ֺ� ��ĭ�� ��� û�ҵ� ��ĭ�̶��
�ٶ󺸴� ���� ���� ���� -> 1�����ΰ���
������ ���̶� ���� ���Ѵٸ� �۵� ���߱�

*/

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
		// �� ����غ���
		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < M; j++)
		//		cout << MAP[i][j];
		//	cout << endl;
		//}
		//cout << ans << endl;


		// 1. ���� ĭ û���ϱ�
		if (MAP[y][x] == 0)
		{
			ans++;
			MAP[y][x] = -1;
		}
		// ���� û���� ĭ ���ϱ�

		// 1. �ݽð�� ȸ���ϱ�

		int flag = 0;
		for (int i = 1; i <= 4; i++)
		{
			// û�ҵ��� ���� ��ĭ ã��
			int nd = d - i;
			if (nd < 0) nd += 4;

			int ny = y + Dr[0][nd];
			int nx = x + Dr[1][nd];
			//cout << ny << " " << nx << " " << MAP[ny][nx] << endl;
			if (MAP[ny][nx] == 0)
			{
				// û�ҵ��� ���� ��ĭ�̶�� ��ĭ �����ϱ�
				y = ny;
				x = nx;
				d = nd;
				flag = 1;
				break;
			}
		}

		// ��ĭ�� �ִµ� ��ã�� �ִ�

		if (flag) continue; // û���� ��ĭ ã�Ҵٸ� �ٽ� 1���� ����

		// �ֺ��� û���� ��ĭ�̾��ٸ�

		// �ٶ󺸴� ������ ������ä�� ��ĭ �����ϰ� 1������ ���ư���
		int by = y - Dr[0][d];
		int bx = x - Dr[1][d];


		// ���̶�� �۵� ���߱�
		if (by < 0 || by >= N || bx < 0 || bx >= M) break;
		if (MAP[by][bx] == 1) break;

		y = by;
		x = bx;
	}

	// ��� : û���ϴ� ĭ�� ����
	cout << ans;

	return 0;
}