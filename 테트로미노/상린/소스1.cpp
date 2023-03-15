#include <iostream>

using namespace std;

// 14500. ��Ʈ�ι̳�

int MAX = 0;

// ����迭
int Dr[2][4] = {
    -1,0,0,1,
    0,-1,1,0,
};

// N���̼��� M���̰��� (4<=N,M<=500)
int N, M;
int MAP[500][500];

// �湮���
int visited[500][500];

// debugging ��
// int path[2][4];

void DFS(int now, int sum, int nowy, int nowx)
{
    if (now == 4)
    {
        MAX = max(MAX, sum);
        return;
    }

    // �׹������� ������
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
    // �� �� �� �� <- DFS�� �ذ����� ���ϴ� ���

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

    // 4�� -> ��� ��ġ���� �ѹ��� ������ DFS
    // + �� �ڸ� �ѹ� �� �����־����
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = 1;
            DFS(1, MAP[i][j], i, j);
            visited[i][j] = 0;

            // �� ���� ���� ���ϱ�
            PLUS(i, j);
        }
    }

    // ���� �ִ�
    cout << MAX;

    return 0;
}