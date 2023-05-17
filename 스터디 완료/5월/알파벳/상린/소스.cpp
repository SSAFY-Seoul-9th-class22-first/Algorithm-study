#include <iostream>

using namespace std;

int R,C;
int DAT[256];
string MAP[20];
int ans;

int Dr[2][4]={
	-1,1,0,0,
	0,0,-1,1,
};

void DFS(int y, int x,int num)
{
	if (num>ans) ans=num;

	for (int i=0;i<4;i++)
	{
		int nexty = y + Dr[0][i];
		int nextx = x + Dr[1][i];

		if (nexty<0||nextx<0||nexty>=R||nextx>=C) continue;
		if (DAT[MAP[nexty][nextx]]==1) continue;

		DAT[MAP[nexty][nextx]]=1;
		DFS(nexty,nextx,num+1);
		DAT[MAP[nexty][nextx]]=0;
	}
}

int main()
{
	cin >> R >> C;
	for (int i=0;i<R;++i)
	{
		cin >> MAP[i];
	}

	// DFS돌리면서 DAT
	DAT[MAP[0][0]]=1;
	DFS(0,0,1);

	cout << ans;
	return 0;
}