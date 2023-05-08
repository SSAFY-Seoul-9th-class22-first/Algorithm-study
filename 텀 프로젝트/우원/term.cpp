#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<set>

#define R first
#define C second
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
int arr[100010];
int vst[100010];
int fin[100010];
int cyc[100010];

void input() {
    memset(fin, 0, sizeof(fin));
    memset(vst, 0, sizeof(vst));
    memset(cyc, 0, sizeof(cyc));
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
}

void check(int now) {
    vst[now] = 1;
    int nxt = arr[now];
    if (!vst[nxt]) dfs(nxt);
    else if (!fin[nxt]) {
        for (int i = nxt; i != now; i = arr[i]) {
            cyc[i] = 1;
        }
        cyc[now] = 1;
    }
    fin[now] = 1;
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        input();
        for (int i = 1; i <= n; ++i) {
            if (vst[i]) continue;
            check(i);
        }
        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            if (!cyc[i]) ret++;
        }
        cout << ret << "\n";
        int de = 1;
    }
    return 0;
}
