#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int y;
    int x;
};

int Dr[2][4] = {
    -1,1,0,0,
    0,0,-1,1,
};

Node People[410][2]; // taxi : idx 0 승객 : idx 1~
int Distance[400][401]; // 첫번째는 나, 두번째는 타인의 도착지
int N, M, Q;
int MAP[20][20];

int flag; // 택시가 갈 수 없는 경우

void BFS(int idx, int starty, int startx)
{
    queue<int> qy; queue<int> qx;
    qy.push(starty); qx.push(startx);

    // MAP
    int visited[20][20] = { 0 };
    visited[starty][startx] = 1; // 마지막에 1씩 빼기
    
    while (!qy.empty())
    {
        int nowy = qy.front(); qy.pop();
        int nowx = qx.front(); qx.pop();

        for (int i = 0;i < 4;i++)
        {
            int nexty = nowy + Dr[0][i];
            int nextx = nowx + Dr[1][i];

            if (nexty<0 || nexty>=N || nextx < 0 || nextx >= N) continue;

            if (MAP[nexty][nextx] == 1) continue; // 장애물

            if (visited[nexty][nextx] > 0) continue;

            visited[nexty][nextx] = visited[nowy][nowx] + 1;
            qy.push(nexty); qx.push(nextx);
        }
    }

    // for문은 승객의 수 : i의 도착지와의 거리 저장 (단, 택시는 출발지)
    for (int i = 0;i <= M;i++)
    {
        Distance[idx][i] = visited[People[i][1].y][People[i][1].x] - 1;
        if (Distance[idx][i] < 0)
        {
            flag = 1; break;
        }
    }
}

int main()
{
    // 19238 스타트 택시
    cin >> N >> M >> Q;

    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            cin >> MAP[i][j]; // 0빈칸 1벽

    cin >> People[0][1].y >> People[0][1].x;

    for (int i = 1;i <= M;i++)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        People[i][0] = { a - 1,b - 1 }; People[i][1] = { c - 1,d - 1 };
    }
    
    for (int i = 1;i <= M;i++)
    {
        // 모든 승객들의 start위치에서 bfs돌리기
        BFS(i, People[i][0].y, People[i][0].x);

        if (flag)
        {
            cout << -1;
            return 0;
        }
    }
    // 계산하기 -> 택시의 이동을 추적하면서 연료 계산 함께하기 초기연료 : Q
    // 택시의 시작 위치 : People[0][1]
    int nowIdx = 0;
    int Ty = People[0][1].y; int Tx = People[0][1].x;
    while (1)
    {
        // 택시가 갈 곳을 정해요 ->
        for (int i = 1;i <= M;i++)
        {

        }


        if (Q < 0)
        { // 연료가 바닥남
            cout << Q; return 0;
        }
    }

    // 출력 : 남은 연료 량 출력
    cout << Q;

    return 0;
}