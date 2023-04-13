#include <iostream>
#include <vector>

using namespace std;

struct shark {
    int speed, direction, size;
};
struct node {
    int y, x;
};

using pns = pair<node, shark>;

int r, c, m;
int ans;
int d[2][5] = {
    0, -1, 1, 0, 0,
    0,  0, 0, 1, -1
};
int backDirection[5] = {
    0, 2, 1, 4, 3
};
shark arr[101][101];
vector<shark> v[101][101];

void init();

pns movingShark(node now, shark nowShark) {
    int speed = nowShark.speed;

    while (speed--) {
        if (speed < 0) break;
        
        int dy = now.y + d[0][nowShark.direction];
        int dx = now.x + d[1][nowShark.direction];

        // 벗어나는 경우
        if (dy == 0) {
            nowShark.direction = backDirection[nowShark.direction];
            dy = 2;
        }
        else if (dy == r + 1) {
            nowShark.direction = backDirection[nowShark.direction];
            dy = r - 1;
        }
        else if (dx == 0) {
            nowShark.direction = backDirection[nowShark.direction];
            dx = 2;
        }
        else if (dx == c + 1) {
            nowShark.direction = backDirection[nowShark.direction];
            dx = c - 1;
        }
        now.y = dy; now.x = dx;
    }

    return { now, nowShark };
}

void moveShark() {

    for (int y = 1; y <= r; y++) {
        for (int x = 1; x <= c; x++) {

            if (arr[y][x].size == 0) continue;
            // 상어가 존재한다면
            shark nowShark = arr[y][x];
            node nowNode = { y, x };
            // first node , second shark
            pns returnValue = movingShark(nowNode, nowShark);

            // 이동한 곳에 상어가 없으면
            if (v[returnValue.first.y][returnValue.first.x].size() == 0) {
                v[returnValue.first.y][returnValue.first.x].push_back(returnValue.second);
            }
            // 상어가 있으면
            else {
                // 기존 상어가 새 상어보다 작으면 바꿔줘야함
                if (v[returnValue.first.y][returnValue.first.x][0].size < returnValue.second.size) {
                    v[returnValue.first.y][returnValue.first.x].clear();
                    v[returnValue.first.y][returnValue.first.x].push_back(returnValue.second);
                }
            }
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            arr[i][j] = { 0, 0, 0 };
            if (v[i][j].size() == 0) continue;
            arr[i][j] = v[i][j][0];
            v[i][j].clear();
        }
    }


}

int main() {

    init();
    //cout << "\n===========================\n";
    //for (int i = 1; i <= r; i++) {
    //    for (int j = 1; j <= c; j++) {
    //        cout.width(5);
    //        cout << arr[i][j].size << ", " << arr[i][j].direction;
    //    }
    //    cout << endl;
    //}
    int manPoint = 0;
    while (manPoint != c) {
        // 낚시왕 오른쪽 한칸 이동
        manPoint++;

        // 현재 열에서 가장 가까운 상어 획득!
        for (int i = 1; i <= r; i++) {
            if (arr[i][manPoint].size > 0) {
                ans += arr[i][manPoint].size;
                arr[i][manPoint] = { 0, 0, 0 };
                break;
            }
        }

        //상어의 이동
        moveShark();
        //cout << "\n===========================\n";
        //for (int i = 1; i <= r; i++) {
        //    for (int j = 1; j <= c; j++) {
        //        cout.width(5);
        //        cout << arr[i][j].size << ", " << arr[i][j].direction;
        //    }
        //    cout << endl;
        //}
    }

    cout << ans;

    return 0;
}

void init() {

    cin >> r >> c >> m;
    for (int i = 0; i < m; i++) {
        int y, x, s, d, z;
        cin >> y >> x >> s >> d >> z;

        // 세로줄일 때
        if (d == 1 or d == 2) s = s % (2 * (r - 1));
        // 가로줄일 때
        else s = s % (2 * (c - 1));

        arr[y][x] = { s, d, z };
    }
}