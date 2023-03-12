#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int y, x;
    int cost;
    bool operator < (node next) const {
        if (cost > next.cost) return true;
        return false;
    }
};

int n, m;
node sn, en;
int arr[55][55];
vector<node> v[55][55];
int dist[55][55];

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) sn = { i, j };
            if (arr[i][j] == 3) en = { i, j };
            if (j > 0) {
                if (arr[i][j] != 0 and arr[i][j - 1] != 0) {
                    v[i][j].push_back({ i, j -1, 0 });
                    v[i][j - 1].push_back({ i, j, 0 });
                }
            }
        }
    }
    
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i][j] == 0) continue;
            for (int e = i + 1; e < n; e++) {
                if (arr[e][j] != 0) {
                    v[i][j].push_back({ e, j, e - i });
                    v[e][j].push_back({ i, j, e - i });
                }
            }
        }
    }

    priority_queue<node> pq;
    pq.push({ sn.y, sn.x, 0 });

    int MAX = 987654321;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) dist[i][j] = MAX;

    dist[sn.y][sn.x] = 0;

    while (!pq.empty()) {
        node now = pq.top();
        pq.pop();

        if (dist[now.y][now.x] < now.cost) continue;

        for (int i = 0; i < v[now.y][now.x].size(); i++) {
            node next = v[now.y][now.x][i];
            int ncost = max(dist[now.y][now.x], abs(next.y - now.y));
            if (dist[next.y][next.x] <= ncost) continue;
            dist[next.y][next.x] = ncost;
            pq.push({ next.y, next.x, ncost });
        }
    }
    
    cout << dist[en.y][en.x];

    return 0;
}