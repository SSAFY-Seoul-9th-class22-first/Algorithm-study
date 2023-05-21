#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

#define T first
#define C second
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
int fullvst ;
vector<pii> adj[20];
int memo[20][1 << 16];

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int a;  cin >> a;
            if (a) adj[i + 1].push_back({ j + 1, a });
        }
    }
    memset(memo, -1, sizeof(memo));
    fullvst = ((1 << n) - 1);
}

int dfs(int now, int vst) {
    if (vst == fullvst) {
        for (int i = 0; i < adj[now].size(); ++i) {
            if (adj[now][i].first == 1) 
                return adj[now][i].second;
        }
        return 1e9;
    }
    if (memo[now][vst] != -1) return memo[now][vst];
    memo[now][vst] = 1e9;
    for (int i = 0; i < adj[now].size(); ++i) {
        int to = adj[now][i].first;
        int cost = adj[now][i].second;
        if ((vst >> (to - 1)) & 1) continue;
        int newvst = vst | (1 << (to - 1));
        memo[now][vst] = min(dfs(to, newvst) + cost, memo[now][vst]);
    }
    return memo[now][vst];
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    input();
    int ret = dfs(1, 1);
    cout << ret;
    return 0;
}
