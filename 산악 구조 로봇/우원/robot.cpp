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

int N, M, T;
int mini = 21e8;
int Map[33][33];
int costs[33][33];

int dy[] = { -1,1,0,0, };
int dx[] = { 0,0,-1,1, };
int inpFlag = 0;
struct tunnul {
    pii coor;
    int cost;
};
vector<tunnul> tunuls[33][33];

void input() {
    cin >> N >> M;
    inpFlag = 0;
    // 높이를 의미함
    for (int y = 1; y <= N; y++) for (int x = 1; x <= N; x++) tunuls[y][x].clear();
    for (int y = 1; y <= N; y++) for (int x = 1; x <= N; x++) { cin >> Map[y][x]; costs[y][x] = 21E8; }
    for (int i = 1; i <= M; i++) {
        int ax, bx, ay, by, cost;
        cin >> ay >> ax >> by >> bx >> cost;
        pii spotA = { ay,ax }; pii spotB = { by,bx };
        tunuls[ay][ax].push_back({ spotB, cost });
        tunuls[by][bx].push_back({ spotA, cost });

    }
}

// 내리막길(현재 위치에서 더 낮은 곳으로 이동할 때)에서는 연료가 소모되지 않습니다.
// 오르막길(현재 위치에서 더 높은 곳으로 이동할 때)에서는 높이 차이의 2배가 소모됩니다.
// 평지(현재 위치에서 같은 높이로 이동할 때)에서는 1의 연료가 소모됩니다.
// 각 터널은 두 위치 A, B를 C의 연료만큼 소모하여 자유롭게 이동할 수 있습니다.
// 조난자의 위치까지 최소 연료를 소비하는 경로를 찾고, 소모된 연료 값을 출력하는 프로그램을 작성하시오. 


void bfs() {
    queue<pii> pq;
    pq.push({ 1,1 });
    costs[1][1] = 0;

    while (!pq.empty())
    {
        auto now = pq.front(); pq.pop(); 
        // 터널이 있다면 (이용하거나 안하거나 )
        for (int i = 0; i < 4; i++) {
            int ny = now.Y + dy[i];
            int nx = now.X + dx[i];

            if (ny < 1 || nx<1 || ny>N || nx>N)continue;

            int cost = costs[now.Y][now.X];
            if (Map[now.Y][now.X] > Map[ny][nx]) cost += 0;
            if (Map[now.Y][now.X] == Map[ny][nx]) cost += 1;
            if (Map[now.Y][now.X] < Map[ny][nx]) cost += 2 * (Map[ny][nx] - Map[now.Y][now.X]);

            if (costs[ny][nx] <= cost) continue;
            costs[ny][nx] = cost;
            pq.push({ ny,nx });
        }
        for (int i = 0; i < tunuls[now.Y][now.X].size(); i++) {
            auto tmp = tunuls[now.Y][now.X][i];
            int cost = costs[now.Y][now.X] + tmp.cost;
            if (costs[tmp.coor.Y][tmp.coor.X] <= cost) continue;
            costs[tmp.coor.Y][tmp.coor.X] = cost;
            pq.push({ tmp.coor.Y,tmp.coor.X });   
        }        
    }
}

int main()
{
    cin >> T;
    for (int t = 0; t < T; t++) {
        input();
        bfs();
        cout << "#" << t + 1 << " " << costs[N][N] << endl;
    }
    return 0;
}
