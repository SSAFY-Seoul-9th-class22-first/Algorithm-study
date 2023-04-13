#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>

#define Y first
#define X second

using namespace std;
using pii = pair<int, int>;

int T, H, W;
int Map[55][55];
int vst[55][55];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

pii target;
pii snowmanInit;
int limit;

struct snowman
{
    int y, x, cnt;
};

void input() {
    cin >> H >> W;
    limit = 0;
    for (int y = 0; y < H; y++)for (int x = 0; x < W; x++) {
        cin >> Map[y][x];
        if (Map[y][x] == 2) { snowmanInit.Y = y; snowmanInit.X = x; }
        if (Map[y][x] == 3) { target.Y = y; target.X = x; }
    }
}
void bfs() {
    queue<snowman> q;
    q.push({ snowmanInit.Y, snowmanInit.X, 0 });
    vst[snowmanInit.Y][snowmanInit.X] = 1;
    while (!q.empty())
    {
        auto now = q.front(); q.pop(); ;
        if (Map[now.y][now.x] == 1) now.cnt = 0;
        // 좌우 이동
        for (int i = 2; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            if (vst[ny][nx] != 0) continue;
            if (Map[ny][nx] == 0) continue;
            if (now.cnt >= 1) continue;
            vst[ny][nx] = 1;
            q.push({ ny,nx,0 });
        }
        // 상하
        for (int i = 0; i < 2; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            if (vst[ny][nx] != 0) continue;
            if (now.cnt >= limit)continue;
            vst[ny][nx] = 2;
            q.push({ ny,nx,now.cnt+1});
        }
    }
}

int main()
{
    int flag = 1;
    input();
    while (flag)
    {
        memset(vst, 0, sizeof(vst));
        bfs();
        if (vst[target.Y][target.X] == 0) limit++;
        if (vst[target.Y][target.X] != 0) flag = 0;
    }
    cout << limit;
    return 0;
}
