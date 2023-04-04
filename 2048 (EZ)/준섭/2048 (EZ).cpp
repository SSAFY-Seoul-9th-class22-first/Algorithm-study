#include <iostream>

using namespace std;
struct node {
    int num, flag;
};
node arr[21][21];
int n;
int ans;

void dfs(int level, int dir, node arr1[21][21]) {
    if (level == 5) {
        return;
    }
    node save[21][21] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            save[i][j] = arr1[i][j];
            save[i][j].flag = 0;
        }
    }
    if (dir == 0) {
        // 상
        for (int x = 0; x < n; x++) {
            int s = 0; int e = 1;
            while (1) {
                if (e == n) break;
                if (save[s][x].num == 0 and save[e][x].num == 0) {
                    e++;
                }
                else if (save[s][x].num == 0 and save[e][x].num != 0) {
                    save[s][x].num = save[e][x].num;
                    save[e][x].num = 0;
                    e++;
                }
                else if (save[s][x].num == save[e][x].num) {
                    if (save[s][x].flag == 0) {
                        save[s][x].flag = 1;
                        save[e][x].num = 0;
                        save[s][x].num = save[s][x].num << 1;
                        ans = max(ans, save[s][x].num);
                    }
                    else {
                        save[s + 1][x].num = save[e][x].num;
                        save[e][x].num = 0;
                        s++;
                    }
                    e++;
                }
                else if (save[s][x].num != 0 and save[e][x].num == 0) {
                    e++;
                }
                else if (save[s][x].num != 0 and save[e][x].num != 0) {
                    if (abs(s - e) > 1) {
                        save[s + 1][x].num = save[e][x].num;
                        save[e][x].num = 0;
                    }
                    s++; e++;
                }

            }
        }
    }
    else if (dir == 1) {
        // 하
        for (int x = 0; x < n; x++) {
            int s = n - 1; int e = n - 2;
            while (1) {
                if (e == -1) break;
                if (save[s][x].num == 0 and save[e][x].num == 0) {
                    e--;
                }
                else if (save[s][x].num == 0 and save[e][x].num != 0) {
                    save[s][x].num = save[e][x].num;
                    save[e][x].num = 0;
                    e--;
                }
                else if (save[s][x].num == save[e][x].num) {
                    if (save[s][x].flag == 0) {
                        save[s][x].flag = 1;
                        save[e][x].num = 0;
                        save[s][x].num = save[s][x].num << 1;
                        ans = max(ans, save[s][x].num);
                    }
                    else {
                        save[s - 1][x].num = save[e][x].num;
                        save[e][x].num = 0;
                        s--;
                    }
                    e--;
                }
                else if (save[s][x].num != 0 and save[e][x].num == 0) {
                    e--;
                }
                else if (save[s][x].num != 0 and save[e][x].num != 0) {
                    if (abs(s - e) > 1) {
                        // 중간에 여백이 있는 경우
                        save[s - 1][x].num = save[e][x].num;
                        save[e][x].num = 0;
                    }
                    s--; e--;
                }

            }
        }
    }
    else if (dir == 2) {
        // 좌
        for (int y = 0; y < n; y++) {
            int s = n - 1; int e = n - 2;
            while (1) {
                if (e == -1) break;
                if (save[y][s].num == 0 and save[y][e].num == 0) {
                    e--;
                }
                else if (save[y][s].num == 0 and save[y][e].num != 0) {
                    save[y][s].num = save[y][e].num;
                    save[y][e].num = 0;
                    e--;
                }
                else if (save[y][s].num == save[y][e].num) {
                    if (save[y][s].flag == 0) {
                        save[y][s].flag = 1;
                        save[y][e].num = 0;
                        save[y][s].num = save[y][s].num << 1;
                        ans = max(ans, save[y][s].num);
                    }
                    else {
                        save[y][s-1].num = save[y][e].num;
                        save[y][e].num = 0;
                        s--;
                    }
                    e--;
                }
                else if (save[y][s].num != 0 and save[y][e].num == 0) {
                    e--;
                }
                else if (save[y][s].num != 0 and save[y][e].num != 0) {
                    if (abs(s - e) > 1) {
                        save[y][s - 1].num = save[y][e].num;
                        save[y][e].num = 0;
                    }
                    s--; e--;

                }

            }
        }
    }
    else if (dir == 3) {
        // 우
        for (int y = 0; y < n; y++) {
            int s = 0; int e = 1;
            while (1) {
                if (e == n) break;
                if (save[y][s].num == 0 and save[y][e].num == 0) {
                    e++;
                }
                else if (save[y][s].num == 0 and save[y][e].num != 0) {
                    save[y][s].num = save[y][e].num;
                    save[y][e].num = 0;
                    e++;
                }
                else if (save[y][s].num == save[y][e].num) {
                    if (save[y][s].flag == 0) {
                        save[y][s].flag = 1;
                        save[y][e].num = 0;
                        save[y][s].num = save[y][s].num << 1;
                        ans = max(ans, save[y][s].num);
                    }
                    else {
                        save[y][s + 1].num = save[y][e].num;
                        save[y][e].num = 0;
                        s++;
                    }
                    e++;
                }
                else if (save[y][s].num != 0 and save[y][e].num == 0) {
                    e++;
                }
                else if (save[y][s].num != 0 and save[y][e].num != 0) {
                    if (abs(s - e) > 1) {
                        save[y][s + 1].num = save[y][e].num;
                        save[y][e].num = 0;
                    }
                    s++; e++;
                }

            }
        }
    }

    for (int i = 0; i < 4; i++) {
        dfs(level + 1, i, save);
    }
}

void solve() {

    for (int i = 0; i < 4; i++) {
        dfs(0, i, arr);
    }
    cout << ans;
}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j].num;
            ans = max(ans, arr[i][j].num);
        }
    }

    solve();
    return 0;
}