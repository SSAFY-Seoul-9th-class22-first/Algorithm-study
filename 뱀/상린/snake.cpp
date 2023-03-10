#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

/*
����
���� ó���� �������� ����
���� ���ʸ��� �̵�

���� ���� ������ ǥ���س��� but ���κ��� ��� �̵� �����ϹǷ� �����س���

�� : 0��ĭ -1��� 1��
*/

int Dr[2][4] = {
	0,1,0,-1,
	1,0,-1,0
}; // �ʱⰪ �����ʺ��� �ð�������� ���� �������� 0,1,2,3

struct Snake {
	int y;
	int x;
};

struct Roll {
	int t;
	int dr;
};

int main()
{
	int N; cin >> N; // ������ ũ��
	int K; cin >> K; // ����� ����
	int MAP[100][100] = { 0 }; // ���� 0���� �ʱ�ȭ
	for (int i = 0; i < K; i++)
	{
		int y, x; cin >> y >> x;
		MAP[y - 1][x - 1] = -1; // ����� ��ġ�� �ʿ� ǥ��
	}
	int L; cin >> L; // ���� ��ȯ Ƚ��
	vector<Roll> roll; // ȸ���ϴ� �ð��� ����
	int before = 0;
	for (int i = 0; i < L; i++)
	{
		int a; // 0�������� a�ʰ� ���� �ڿ� �̵�
		char b; // �̵����� : L���� D������ ȸ��
		cin >> a >> b;

		if (b == 'L')
		{
			// ���� ȸ�� -1
			before--;
			if (before == -1) before = 3;
		}
		else
		{
			// ������ ȸ�� +1
			before++;
			if (before == 4) before = 0;
		}
		roll.push_back({ a,before });
	}

	// �ð��� �帧�� ���� ������ �����ϱ� - ������ �� : 
	int time = 0;
	int rolltimeidx = 0;
	int nowdr = 0;
	queue<Snake> snake;
	Snake head = { 0,0 };
	// ������ �� ó�� ��ġ�� ǥ���ϱ� + �� �� �ֱ�
	MAP[0][0] = 1;
	snake.push({ 0,0 });


	//for (int i = 0; i < roll.size(); i++)
	//{
	//	cout << roll[i].dr << " ";
	//}

	while (1)
	{
		// �ð��� �귶��
		time++;

		// �̵��ϴ� �������� ���� �Ӹ��� �� ĭ �����̱�
		int Y = head.y + Dr[0][nowdr];
		int X = head.x + Dr[1][nowdr];

		// break : ���� ���̶�
		if (Y < 0 || Y >= N || X < 0 || X >= N) break;


		// �̵��ϱ� -> ���� ����
		if (MAP[Y][X] == 0)
		{
			// MAP�� ǥ�� �����
			MAP[snake.front().y][snake.front().x] = 0;

			// queue���� ���� ����
			snake.pop();
		}

		// break : ���� �ڱ� �ڽ��̶� �´���� ��
		if (MAP[Y][X] == 1) break;

		// 1. ����� �ִ� - ��� �԰�, ���� �״�� - �ʿ� ����� ���ְ�, ������ �ٲٱ�
		// 2. ��ĭ�� �� �ʿ� ������ �ٲٱ�
		MAP[Y][X] = 1;
		snake.push({ Y ,X });
		head = { Y,X };



		// �ش��ϴ� �ʿ� ������ �ٲٴ��� Ȯ�� - �ش� �ʰ� ������ ������ �ٲٰ� �ȴ�
		if (rolltimeidx < roll.size() && roll[rolltimeidx].t == time)
		{
			nowdr = roll[rolltimeidx].dr;
			rolltimeidx++;
		}

		// �� ǥ��
		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//		cout << MAP[i][j];
		//	cout << endl;
		//}
		//cout << endl;

	}


	// ��� : ������ ���ʿ� �����°�?
	cout << time;

	return 0;
}