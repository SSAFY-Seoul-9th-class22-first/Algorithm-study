#include <iostream>
#include <vector>
#include <vector>

using namespace std;
/*
G개의 게이트 1~G
P개의 비행기 순서대로 도착예정
*/

int G, P;
int parent[100001];

int Find(int a)
{
	if (parent[a] == a)
		return a;
	else return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);
	if (pa == pb)
		return;

	parent[pa] = pb;

	return;
}

int main()
{

	cin >> G;
	cin >> P;
	int ans = 0;
	vector <int> gi(P);
	vector <int> gate(G+1);

	for (int i = 0; i <= G; i++)
		parent[i] = i;

	for (int i = 0; i < P; i++)
	{
		cin >> gi[i];
	}

	for (int i = 0; i <P; i++)
	{
		if (Find(gi[i]) == 0)
			break;
		else
		{
			ans++;
			Union(Find(gi[i]), Find(gi[i]) - 1);
			
		}
	}
	
	cout << ans;

	return 0;
}