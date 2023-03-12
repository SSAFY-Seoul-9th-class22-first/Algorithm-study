#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

/*
설계
뱀은 처음에 오른쪽을 향함
뱀은 매초마다 이동

뱀의 몸을 지도에 표시해놓기 but 끝부분은 계속 이동 가능하므로 저장해놓기

맵 : 0빈칸 -1사과 1뱀
*/

int Dr[2][4] = {
	0,1,0,-1,
	1,0,-1,0
}; // 초기값 오른쪽부터 시계방향으로 도는 방향으로 0,1,2,3

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
	int N; cin >> N; // 보드의 크기
	int K; cin >> K; // 사과의 개수
	int MAP[100][100] = { 0 }; // 맵은 0으로 초기화
	for (int i = 0; i < K; i++)
	{
		int y, x; cin >> y >> x;
		MAP[y - 1][x - 1] = -1; // 사과의 위치를 맵에 표시
	}
	int L; cin >> L; // 방향 변환 횟수
	vector<Roll> roll; // 회전하는 시간과 방향
	int before = 0;
	for (int i = 0; i < L; i++)
	{
		int a; // 0에서부터 a초가 끝난 뒤에 이동
		char b; // 이동방향 : L왼쪽 D오른쪽 회전
		cin >> a >> b;

		if (b == 'L')
		{
			// 왼쪽 회전 -1
			before--;
			if (before == -1) before = 3;
		}
		else
		{
			// 오른쪽 회전 +1
			before++;
			if (before == 4) before = 0;
		}
		roll.push_back({ a,before });
	}

	// 시간의 흐름에 따라 게임을 진행하기 - 게임의 끝 : 
	int time = 0;
	int rolltimeidx = 0;
	int nowdr = 0;
	queue<Snake> snake;
	Snake head = { 0,0 };
	// 지도에 뱀 처음 위치를 표시하기 + 뱀 몸 넣기
	MAP[0][0] = 1;
	snake.push({ 0,0 });


	//for (int i = 0; i < roll.size(); i++)
	//{
	//	cout << roll[i].dr << " ";
	//}

	while (1)
	{
		// 시간이 흘렀다
		time++;

		// 이동하는 방향으로 뱀의 머리를 한 칸 움직이기
		int Y = head.y + Dr[0][nowdr];
		int X = head.x + Dr[1][nowdr];

		// break : 뱀이 벽이랑
		if (Y < 0 || Y >= N || X < 0 || X >= N) break;


		// 이동하기 -> 꼬리 빼기
		if (MAP[Y][X] == 0)
		{
			// MAP에 표시 지우기
			MAP[snake.front().y][snake.front().x] = 0;

			// queue에서 꼬리 빼기
			snake.pop();
		}

		// break : 뱀이 자기 자신이랑 맞닿았을 때
		if (MAP[Y][X] == 1) break;

		// 1. 사과가 있다 - 사과 먹고, 꼬리 그대로 - 맵에 사과를 없애고, 뱀으로 바꾸기
		// 2. 빈칸일 때 맵에 뱀으로 바꾸기
		MAP[Y][X] = 1;
		snake.push({ Y ,X });
		head = { Y,X };



		// 해당하는 초에 방향을 바꾸는지 확인 - 해당 초가 끝나고 방향을 바꾸게 된다
		if (rolltimeidx < roll.size() && roll[rolltimeidx].t == time)
		{
			nowdr = roll[rolltimeidx].dr;
			rolltimeidx++;
		}

		// 뱀 표시
		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//		cout << MAP[i][j];
		//	cout << endl;
		//}
		//cout << endl;

	}


	// 출력 : 게임이 몇초에 끝나는가?
	cout << time;

	return 0;
}