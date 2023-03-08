#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
struct Edge {
    int y, x; // 어디로 향하는 간선이고?
    int cost; // 가중치
    bool operator < (Edge next) const {
        // 내가 원하는 상황 
        if (cost < next.cost)
            return false;
        if (cost > next.cost)
            return true;
        // 항상 무지성 false 
        return false;
    }
};
vector<Edge> defVector[33][33];

void init() {
    int d[2][4] = {
        1, 0, -1, 0,
        0, 1, 0, -1
    };
    
    cin >> n >> m;
    int arr[33][33] = { 0, };
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> arr[i][j];

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            defVector[y][x].clear();
            for (int dir = 0; dir < 4; dir++) {
                int dy = y + d[0][dir]; int dx = x + d[1][dir];
                if (dy == 0 or dx == 0 or dy == n + 1 or dx == n + 1) continue;
                if (arr[y][x] > arr[dy][dx]) defVector[y][x].push_back({ dy, dx, 0 });
                else if (arr[y][x] == arr[dy][dx]) defVector[y][x].push_back({ dy, dx, 1 });
                else defVector[y][x].push_back({ dy, dx, (arr[dy][dx] - arr[y][x]) * 2 });
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int ay, ax, by, bx, c;
        cin >> ay >> ax >> by >> bx >> c;
        defVector[ay][ax].push_back({ by, bx, c });
        defVector[by][bx].push_back({ ay, ax, c });
    }
}

int dij() {
    priority_queue<Edge> pq;
    // 시작점 설정
    pq.push({ 1, 1, 0 });
    int dist[33][33] = { 0, };
    int MAX = 987654321;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dist[i][j] = MAX;
    dist[1][1] = 0;

    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();

        if (dist[now.y][now.x] < now.cost) continue;
        for (int i = 0; i < defVector[now.y][now.x].size(); i++) {
            Edge next = defVector[now.y][now.x][i];
            int ncost = dist[now.y][now.x] + next.cost;
            if (dist[next.y][next.x] <= ncost) continue;
            dist[next.y][next.x] = ncost;
            pq.push({ next.y, next.x, ncost });
        }
    }
    return dist[n][n];
}

int main() {

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {

        init();
        cout << "#" << t << " " << dij() << endl;
    }

    return 0;
}