#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[55][55];
struct node {
    int y, x;
};
int d[2][4] = {
    -1, 0, 1, 0,
    0, 1, 0, -1
};
int backD[4] = {
    2, 3, 0, 1
};

int n, m;
node sn;

bool cleanCheck(int y, int x) {
    for (int dir = 0; dir < 4; dir++) {
        int dy = y + d[0][dir];
        int dx = x + d[1][dir];
        if (dy == 0 or dx == 0 or dy > n or dx > m) continue;
        if (arr[dy][dx] == 0) return true;
    }
    return false;
}

int main() {

    int dir = 0;
    cin >> n >> m;
    cin >> sn.y >> sn.x >> dir;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> arr[i][j];

    node now = { sn.y + 1, sn.x + 1 };
    int ans = 0;
    while (1) {
        if (arr[now.y][now.x] == 0) {
            arr[now.y][now.x] = 2;
            ans++;
        }

        if (cleanCheck(now.y, now.x)) {
            // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
            dir--;
            if (dir < 0) dir = 3;
            int dy = now.y + d[0][dir]; int dx = now.x + d[1][dir];
            if (dy == 0 or dx == 0 or dy > n or dx > m) continue;
            if (arr[dy][dx] == 0) {
                // 청소되지 않은 빈 칸인 경우
                now.y = dy; now.x = dx;
            }
        }
        else {
            // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
            int dy = now.y + d[0][backD[dir]]; int dx = now.x + d[1][backD[dir]];
            if (dy == 0 or dx == 0 or dy > n or dx > m or (arr[dy][dx] == 1)) {
                cout << ans;
                return 0;
            }
            now.y = dy; now.x = dx;

        }
    }

    return 0;
}