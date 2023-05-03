#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[35000];
int backnum[35000];
queue<int> q;

int main()
{
    
    int N, M; cin >> N >> M;
    for (int i = 0;i < M;i++)
    {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        backnum[b]++;
    }

    // 0 push
    for (int i = 1;i <= N;i++)
    {
        if (backnum[i] == 0) q.push(i);
    }

    // queue
    while (!q.empty())
    {
        int now = q.front(); q.pop();

        // 현재 정점
        cout << now << " ";

        // for문
        for (int i = 0;i < v[now].size();i++)
        {
            backnum[v[now][i]]--;
            if (backnum[v[now][i]] == 0) q.push(v[now][i]);
        }
    }

    return 0;
}