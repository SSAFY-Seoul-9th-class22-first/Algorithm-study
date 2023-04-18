#include <iostream>

using namespace std;

int parent[505];
int used[505];
int cycle[505];

int Find(int now) {
    if (now == parent[now])
        return now;
    return parent[now] = Find(parent[now]);
}

void Union(int A, int B) {
    // #1. 각 A와 B의 소속을 확인
    int pa = Find(A);
    int pb = Find(B);

    // 또 같은 부모를 유니온 한다는 것은 순환한다는 증거!
    if (pa == pb) {
        cycle[pa] = 1;
        return; // 함수 종료
    }
    // #2. B의 소속을 A의 소속의 산하로 만든다!
    parent[pb] = pa;
}

int main() {
    int T = 0;
    while (1) {

        int n, m, ans;
        ans = 0;
        cin >> n >> m;

        // 종료 조건
        if (n == 0 and m == 0) return 0;

        // 배열 초기화
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            used[i] = 0;
            cycle[i] = 0;
        }

        // 간선의 수만큼 입력 받기
        while (m--) {
            int from, to;
            cin >> from >> to;
            Union(from, to);
        }

        for (int i = 1; i <= n; i++) {
            if (cycle[parent[i]] == 1) {
                cycle[Find(i)] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (cycle[Find(i)] == 1) continue;
            if (used[Find(i)] == 0) {
                ans++;
                used[Find(i)] = 1;
            }
        }

        T++;
        if (ans == 0) {
            cout << "Case " << T << ": No trees.\n";
        }
        else if (ans == 1) {
            cout << "Case " << T << ": There is one tree.\n";
        }
        else {
            cout << "Case " << T << ": A forest of " << ans << " trees.\n";
        }
    }
}