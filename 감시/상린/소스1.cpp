#include <iostream>
#include <vector>

using namespace std;

// 15683. 감시

struct Node {
    int y;
    int x;
};

int Dr[2][4] = {
    0,1,0,-1,
    1,0,-1,0,
};

vector<Node> cctv;
int MAP[8][8];
int path[8]; // CCTV최대 8개

int ans = 21e8; // 출력 : 사각지대 최소 크기 <- 0의 개수 최소

int N, M;


int C_MAP[8][8];
// Go
void Go(Node now, int d)
{
    int nowy = now.y;
    int nowx = now.x;
    while (1)
    {
        // 벽이나 갈 데가 없다면 break;
        nowy += Dr[0][d];
        nowx += Dr[1][d];
        //cout << nowy << " " << nowx << endl;
        // 갈수없다면
        if (nowy < 0 || nowy >= N || nowx < 0 || nowx >= M) break;

        // 벽이라면
        if (C_MAP[nowy][nowx] == 6) break;
        //cout << nowy << " " << nowx << endl;
        // 맵에 표시하고 계속 가기
        C_MAP[nowy][nowx] = -1;
    }
}


int Cal()
{
    int rst = 0;

    // 맵 복사하기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            C_MAP[i][j] = MAP[i][j];
        }
    }

    // 해당 방향으로 돌리기
    for (int i = 0; i < cctv.size(); i++)
    {
        // 해당 cctv 번호
        int num = MAP[cctv[i].y][cctv[i].x];

        if (num == 1)
        {
            if (path[i]==0) Go(cctv[i], 0);
            else if (path[i]==1) Go(cctv[i],1);
            else if (path[i] == 2) Go(cctv[i], 2);
            else if (path[i] == 3) Go(cctv[i], 3);
        }
        else if (num == 2)
        {
            if (path[i]%2==0)
            {
                Go(cctv[i], 0);
                Go(cctv[i], 2);
            }
            else
            {
                Go(cctv[i], 1);
                Go(cctv[i], 3);
            }
        }
        else if (num == 3)
        {
            if (path[i] == 0)
            {
                Go(cctv[i], 3);
                Go(cctv[i], 0);
            }
            else if (path[i] == 1)
            {
                Go(cctv[i], 0);
                Go(cctv[i], 1);
            }
            else if (path[i] == 2)
            {
                Go(cctv[i], 1);
                Go(cctv[i], 2);
            }
            else if (path[i] == 3)
            {
                Go(cctv[i], 2);
                Go(cctv[i], 3);
            }
        }
        else if (num == 4)
        {
            if (path[i] == 0)
            {
                Go(cctv[i], 2);
                Go(cctv[i], 3);
                Go(cctv[i], 0);
            }
            else if (path[i] == 1)
            {
                Go(cctv[i], 3);
                Go(cctv[i], 0);
                Go(cctv[i], 1);
            }
            else if (path[i] == 2)
            {
                Go(cctv[i], 0);
                Go(cctv[i], 1);
                Go(cctv[i], 2);
            }
            else if (path[i] == 3)
            {
                Go(cctv[i], 1);
                Go(cctv[i], 2);
                Go(cctv[i], 3);
            }
        }
        else if (num == 5)
        {
            Go(cctv[i], 0);
            Go(cctv[i], 1);
            Go(cctv[i], 2);
            Go(cctv[i], 3);
        }

    }


    // 0의 개수 구하기
    //cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (C_MAP[i][j] == 0) rst++;

            //cout << C_MAP[i][j];

        }
        //cout << endl;
    }
    //cout << endl;
    //cout << rst;
    return rst;
}

void DFS(int now)
{
    if (now == cctv.size())
    {
        // 계산하기
        ans = min(ans, Cal());

        return;
    }

    // 0,1,2,3중 선택하기 번호마다 달라
    for (int i = 0; i < 4; i++)
    {
        //if (MAP[cctv[now].y][cctv[now].x] == 2 && i > 1) continue;
        //if (MAP[cctv[now].y][cctv[now].x] == 5) continue;

        path[now] = i;
        DFS(now + 1);
        path[now] = 0;
    }
}


int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];

            if (MAP[i][j] >= 1 && MAP[i][j] <= 5)
                cctv.push_back({ i,j });

        }
    }

    // DFS로 선택하기
    DFS(0);

    cout << ans;

    return 0;
}