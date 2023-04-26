// https://www.acmicpc.net/problem/1275

#include <string>
#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
using ll = long long int;

int n, m;
vector<int> numbers;
ll tree[100100 * 4];

void input() {
    cin >> n >> m;
    numbers.assign(n, 0);
    for (int& n : numbers) cin >> n;
    /*for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }*/
}

ll maketree(int s=0, int e = n-1, int x = 1) {
    if (s == e) return tree[x] = numbers[s];
    int mid = s + e >> 1;
    maketree(s, mid, x << 1);
    maketree(mid+1, e, x << 1 | 1);
    return tree[x] = tree[x << 1] + tree[x << 1 | 1];
}

ll query(int l, int r, int s = 0, int e = n - 1, int x = 1) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return tree[x];
    int mid = s + e >> 1;
    return query(l, r, s, mid, x << 1) + query(l, r, mid + 1, e, x << 1 | 1);
}

void update(int idx, int b, int s = 0, int e = n - 1, int x = 1) {
    if (idx < s || idx > e) return;
    if (s == e) {
        tree[x] = b;
        return;
    } 
    int mid = s + e >> 1;
    update(idx, b, s, mid, x << 1);
    update(idx, b, mid+1, e, x << 1|1);
    tree[x] = tree[x << 1] + tree[x << 1 | 1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    maketree();

    for (int i = 0; i < m; ++i) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int l = a < b ? a : b;
        int r = a < b ? b : a;
        cout << query(l-1, r-1) << "\n";
        update(c-1, d);
    }
    return 0;
}
