#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int T, N,M;
int a, b;
vector<int>v[50001];
int check[50001];
int d[50001];
int p[50001];

void saveDepth(int x, int depth)
{
	check[x] = 1;
	d[x] = depth;
	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		if (check[y] == 1)
			continue;
		p[y] = x;
		saveDepth(y, depth + 1);
	}

	return;
}

/*
void findPerents()
{
	for (int i = 1; i < ceil(log2(N)); i++)
	{
		for (int j = 1; j <= N; j++)
		{
			p[j][i] = p[p[j][i-1]][i - 1];
		}
	}
	return;
}
*/
int lca(int a, int b)
{
	int aa = a, bb = b;
	while (d[aa] != d[bb])
	{
		if (d[aa] < d[bb])
		{

			bb = p[bb];
		}
		else if (d[aa] > d[bb])
		{

			aa = p[aa];
		}
	}
	//cout << aa << " " << bb << endl;
	while (aa != bb)
	{
		aa = p[aa];
		bb = p[bb];

	}
	return aa;
}

int main()
{
		cin >> N;
		for (int i = 0; i < N - 1; i++)
		{
			int a, b;
			cin >> a >> b;
				v[a].push_back(b);
			
				v[b].push_back(a);
			
		}
	
		
		saveDepth(1, 0);
		//findPerents();
		
		/*
		for (int i = 1; i < N+1; i++)
			cout << d[i] << " ";
		cout << endl;

		for (int i = 1; i < N + 1; i++)
			cout << p[i]<< " ";
		cout << endl;
		*/
		
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			cout << lca(a, b) << endl;

		}
	return 0;
}