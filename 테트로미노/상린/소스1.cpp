#include <iostream>

using namespace std;

// 14500. 테트로미노

int MAX = 0;

// 방향배열
int Dr[2][4] = {
    -1,0,0,1,
    0,-1,1,0,
};

// N종이세로 M종이가로 (4<=N,M<=500)
int N, M;
int MAP[500][500];

// 방문기록
int visited[500][500];

// debugging 용
// int path[2][4];

void DFS(int now, int sum, int nowy, int nowx)
{
    if (now == 4)
    {
        MAX = max(MAX, sum);
        return;
    }

    // 네방향으로 돌리기
    for (int i = 0; i < 4; i++)
    {
        int Y = nowy + Dr[0][i];
        int X = nowx + Dr[1][i];

        if (Y < 0 || X < 0 || Y >= N || X >= M) continue;

        if (visited[Y][X] == 1) continue;

        visited[Y][X] = 1;
        DFS(now + 1, sum + MAP[Y][X], Y, X);
        visited[Y][X] = 0;
    }
}

void PLUS(int nowy, int nowx)
{
    // ㅓ ㅏ ㅜ ㅗ <- DFS로 해결하지 못하는 모양

    for (int i = 0; i < 4; i++)
    {
        int sum = MAP[nowy][nowx];
        for (int j = 0; j < 4; j++)
        {
            if (i == j) continue;

            int Y = nowy + Dr[0][j];
            int X = nowx + Dr[1][j];

            if (Y < 0 || X < 0 || Y >= N || X >= M) break;

            sum += MAP[Y][X];
        }
        MAX = max(MAX, sum);
    }
}

int main()
{
    // input
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> MAP[i][j];

    // 4개 -> 모든 위치에서 한번씩 돌리기 DFS
    // + ㅜ 자를 한번 더 따져주어야함
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = 1;
            DFS(1, MAP[i][j], i, j);
            visited[i][j] = 0;

            // ㅜ 자형 따로 구하기
            PLUS(i, j);
        }
    }

    // 합의 최댓값
    cout << MAX;

    return 0;
}