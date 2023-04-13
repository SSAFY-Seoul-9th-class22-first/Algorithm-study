#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>

#define R first
#define C second

using namespace std;
using pii = pair<int, int>;

int n, m, MAX = 0;
int Map[22][22];
vector<int> path;
void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> Map[i][j];
            MAX = max(MAX, Map[i][j]);
        }
    }
}

void gravity(int dir, int line) {
    int flag; int ret = 0;
    if (dir == 0) {
        for (int r = 0; r <= n - 1; ++r) {
            if (Map[r][line] == 0) {
                flag = 0;
                for (int t = r + 1; t <= n - 1; ++t) {
                    if (Map[t][line] != 0) {
                        Map[r][line] = Map[t][line]; Map[t][line] = 0; flag = 1; break;
                    }
                }
                if (flag == 0) break;
            }
        }
    }
    if (dir == 1) {
        for (int r = n - 1; r >= 0; --r) {
            if (Map[r][line] == 0) {
                flag = 0;
                for (int t = r - 1; t >= 0; --t) {
                    if (Map[t][line] != 0) {
                        Map[r][line] = Map[t][line]; Map[t][line] = 0; flag = 1; break;
                    }
                }
                if (flag == 0) break;
            }
        }
    }
    if (dir == 2) {
        for (int c = 0; c <= n - 1; ++c) {
            if (Map[line][c] == 0) {
                flag = 0;
                for (int t = c + 1; t <= n - 1; ++t) {
                    if (Map[line][t] != 0) {
                        Map[line][c] = Map[line][t]; Map[line][t] = 0; flag = 1; break;
                    }
                }
                if (flag == 0) break;
            }
        }
    }
    if (dir == 3) {
        for (int c = n - 1; c >= 0; --c) {
            if (Map[line][c] == 0) {
                flag = 0;
                for (int t = c - 1; t >= 0; --t) {
                    if (Map[line][t] != 0) {
                        Map[line][c] = Map[line][t]; Map[line][t] = 0; flag = 1; break;
                    }
                }
                if (flag == 0) break;
            }
        }
    }
}

int doit(int dir, int maxval) {
    if (dir == 0) {
        for (int c = 0; c < n; ++c) {
            gravity(0, c);
            for (int r = 1; r < n; ++r) {
                if (Map[r - 1][c] == Map[r][c]) {
                    Map[r - 1][c] += Map[r][c];
                    Map[r][c] = 0;
                    maxval = max(Map[r - 1][c], maxval);
                }
            }
            gravity(0, c);
        }
    }
    if (dir == 1) {
        for (int c = 0; c < n; ++c) {
            gravity(1, c);
            for (int r = n - 2; r >= 0; --r) {
                if (Map[r + 1][c] == Map[r][c]) {
                    Map[r + 1][c] += Map[r][c];
                    Map[r][c] = 0;
                    maxval = max(Map[r + 1][c], maxval);
                }
            }
            gravity(1, c);
        }
    }
    if (dir == 2) {
        for (int r = 0; r < n; ++r) {
            gravity(2, r);
            for (int c = 1; c < n; ++c) {
                if (Map[r][c - 1] == Map[r][c]) {
                    Map[r][c - 1] += Map[r][c];
                    Map[r][c] = 0;
                    maxval = max(Map[r][c - 1], maxval);
                }
            }
            gravity(2, r);
        }
    }
    if (dir == 3) {
        for (int r = 0; r < n; ++r) {
            gravity(3, r);
            for (int c = n - 2; c >= 0; --c) {
                if (Map[r][c + 1] == Map[r][c]) {
                    Map[r][c + 1] += Map[r][c];
                    Map[r][c] = 0;
                    maxval = max(Map[r][c + 1], maxval);
                }
            }
            gravity(3, r);
        }
    }
    return maxval;
}


void dfs(int level, int mx) {
    int cpyMap[22][22];
    if (level == 10) return;
    if (mx * pow(2, 10 - level) <= MAX) return;
    for (int i = 0; i < 4; ++i) {
        memcpy(cpyMap, Map, sizeof(Map));
        int ret = doit(i, mx);
        if (memcmp(cpyMap, Map, sizeof(Map)) == 0) continue;
        MAX = max(MAX, ret);
        dfs(level + 1, ret);
        memcpy(Map, cpyMap, sizeof(Map));
    }
}


int main()
{
    input();
    dfs(0, MAX);
    cout << MAX;
    return 0;
}
