#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    int a, b, cost;
};

bool cmp(node left, node right)
{
    return left.cost < right.cost;
}


int parent[10001];

int find(int now)
{
    if (now == parent[now]) return now;

    return parent[now] = find(parent[now]);
}

void Union(int a, int b)
{
    int pa = find(a);
    int pb = find(b);

    if (pa == pb) return;

    parent[pa] = pb;
}

int main()
{
    vector<node> v;
    int V, E; cin >> V >> E;
    for (int i = 0;i < E;i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        v.push_back({ a,b,cost });
    }

    // 정렬하기
    sort(v.begin(), v.end(), cmp);

    // parent 세팅하기
    for (int i = 0;i < V;i++) parent[i] = i;

    // Union하기
    int sum = 0; // 최종 결과
    for (int i = 0;i < v.size();i++)
    {
        if (find(v[i].a)==find(v[i].b)) continue;

        sum += v[i].cost;

        Union(v[i].a, v[i].b);
    }


    cout << sum;

    return 0;
}