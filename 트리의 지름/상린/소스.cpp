#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
DFS : 한번씩 돌려서 최대값 찾기 -> 인데, 제일 하위 요소들만 돌기
가중치가 있는 노드
*/

struct Node {
	int to, cost;
};

int MAX = 0;
int visited[10001];
int DAT[10001];
vector<Node> v[10001];

void DFS(int now,int sum)
{
	// 갈 수 있는 곳이 더이상 없다면 탈출
	int flag = 0;

	for (int i = 0;i < v[now].size();i++)
	{
		if (visited[v[now][i].to] == 1) continue;
		flag = 1;
		visited[v[now][i].to] = 1;
		DFS(v[now][i].to, sum + v[now][i].cost);
		visited[v[now][i].to] = 0;
	}

	if (!flag)
	{
		MAX = max(MAX, sum);
		return;
	}
}

int main()
{
	// 노드 1번~n번
	int n; cin >> n; // 노드의 개수
	
	for (int i = 0;i < n - 1;i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		DAT[a]++;
		DAT[b]++;
		v[a].push_back({ b,cost });
		v[b].push_back({ a,cost });
	}

	// DAT가 1인 애들부터만 DFS 돌리기
	for (int i = 1;i <= n;i++)
	{
		if (DAT[i] == 1)
		{
			// DFS 돌려서 최대값 찾기
			visited[i] = 1;
			DFS(i,0);
			visited[i] = 0;
		}
	}

	cout << MAX;

	return 0;
}