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

int n, m;
int parent[10010];
struct ftc { int from, to, cost; };
vector<ftc> adj;

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int f, t, c;
        cin >> f >> t >> c;
        adj.push_back({ f,t,c });
    }
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
}

bool cmp(ftc a, ftc b) {
    if (a.cost < b.cost) return true;
    return false;

}

int Find(int num) {
    if (num == parent[num]) return num;
    return parent[num] = Find(parent[num]);
}

void Union(int a, int b) {
    int pa = Find(a); int pb = Find(b);
    if (pa == pb) return;
    parent[pb] = pa;
}

int mst() {
    sort(adj.begin(), adj.end(), cmp);
    int sum = 0; int cnt = 0;
    for (int i = 0; i < adj.size(); ++i) {
        ftc now = adj[i];
        if (Find(now.from) == Find(now.to)) continue;
        Union(now.from, now.to);
        cnt++; sum += now.cost;
    }
    if (cnt == n - 1) return sum;
    else return -1;
}


int main()
{   
    input();
    int ret = mst();
    cout << ret;
    return 0;
}
