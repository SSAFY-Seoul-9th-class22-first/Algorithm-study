#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n, q, l;
int arr[65][65];
int visited[65][65];

struct node {
    int y, x;
};

int d[2][4] = {
    -1, 0, 1, 0,
    0, 1, 0, -1
};


void matrix_rotate(int ysi, int xsi) {

    int tmp[65][65] = { 0 };
    int ttmp[65][65] = { 0 };
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            tmp[i][j] = arr[ysi + i][xsi + j];
        }
    }

    for (int i = 0; i < l; ++i) for (int j = 0; j < l; ++j) {
        ttmp[i][j] = tmp[l - j - 1][i];
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            arr[ysi + i][xsi + j] = ttmp[i][j];
        }
    }
}

bool dc(int y, int x) {

    int cnt = 0;
    for (int dir = 0; dir < 4; dir++) {
        int dy = y + d[0][dir];
        int dx = x + d[1][dir];
        if (dy < 0 or dx < 0 or dy == n or dx == n) continue;
        if (arr[dy][dx] == 0) continue;
        cnt++;
        if (cnt >= 3) return false;
    }
    return true;

}

int bfs(int y, int x) {
    queue<node> q;
    q.push({ y, x });
    visited[y][x] = 1;
    int cnt = 1;
    while (!q.empty()) {
        node now = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int dy = now.y + d[0][dir];
            int dx = now.x + d[1][dir];
            if (dy < 0 or dx < 0 or dy == n or dx == n) continue;
            if (visited[dy][dx] == 1) continue;
            if (arr[dy][dx] == 0) continue;
            cnt++;
            visited[dy][dx] = 1;
            q.push({ dy,dx });

        }
    }

    return cnt;
}

int main() {

    // 초기 설정
    cin >> n >> q;
    n = pow(2, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }



    while (q--) {
        cin >> l;
        l = pow(2, l);

        if (l > 1) {
            for (int i = 0; i < n / l; i++) {
                for (int j = 0; j < n / l; j++) {
                    matrix_rotate(i * l, j * l);
                }
            }
        }

        queue<node> que;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 0) continue;
                if (dc(i, j)) que.push({ i, j });
            }
        }
        while (!que.empty()) {
            arr[que.front().y][que.front().x]--;
            que.pop();
        }
    }
    int ans1 = 0;
    int MAX = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) continue;
            ans1 += arr[i][j];
            if (visited[i][j] != 0) continue;
            int cnt = bfs(i, j);
            if (MAX < cnt) MAX = cnt;
        }
    }

    cout << ans1 << endl;
    cout << MAX;

    return 0;
}