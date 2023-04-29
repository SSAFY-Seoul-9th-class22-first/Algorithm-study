#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// LCA : 최소 공통 조상

vector<int> v[50001];
int depth[50001];
int parent[50001]; // + visited 기능
int main()
{
    // 1. 입력받기
    int N; cin >> N; // 노드의 개수
    for (int i = 0;i < N - 1;i++)
    {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    // 2. 기록하기 : BFS 사용 : visited, depth, parent 필요
    // 항상 1번 정점이 root
    parent[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int now = q.front(); q.pop();

        for (int i = 0;i < v[now].size();i++)
        {
            // 방문했는지 판별
            if (parent[v[now][i]] != 0) continue;
            // 기록
            parent[v[now][i]] = now;
            depth[v[now][i]] = depth[now] + 1;
            q.push(v[now][i]);
        }
    }

    // 3. 공통 조상 찾기
    int M;  cin >> M; // 공통 조상을 알고 싶은 쌍의 개수
    for (int i = 0;i < M;i++)
    {
        // 1) 입력받기
        int a, b; cin >> a >> b;
        // 2) 깊이를 같게 만들어주기 - b가 더 깊도록
        if (depth[a] > depth[b]) swap(a, b);
        // 3) 두 수가 같은 깊이에 있도록
        while (depth[a] != depth[b]) b = parent[b];
        // 4) 동시에 한단계씩 올라가면서 같으면 끝
        while (a != b)
        {
            a = parent[a];
            b = parent[b];
        }
        // 출력 : a와 b의 공통조상
        cout << a << endl;
    }

    return 0;
}