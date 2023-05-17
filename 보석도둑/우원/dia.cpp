#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>

#define R first
#define C second
using namespace std;
using ll = long long int;
using pii = pair<int, int>;

int n, k;
pii dia[300300];
multiset<int> wset;

bool cmp(pii a, pii b) {
    if (a.second > b.second) return true;
    return false;
}

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int m, v;  cin >> m >> v;
        dia[i] = { m,v };
    }
    for (int i = 0; i < k; ++i) {
        int w; cin >> w;
        wset.insert(w);
    }
    sort(dia, dia+n, cmp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    ll ret = 0;
    for (int i = 0; i <n; ++i) {
        pii now = dia[i];
        int weight = now.first;
        multiset<int> ::iterator iter;
        iter = wset.lower_bound(weight);
        if (iter != wset.end()) {
            wset.erase(iter);
            ret += now.second;
        }
    }
    cout << ret;
    int de = 1;
    return 0;
}
