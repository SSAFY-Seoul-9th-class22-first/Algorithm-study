#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

struct X
{
	int x;
	int idx;
};
struct Y
{
	int y;
	int idx;
};
struct Z
{
	int z;
	int idx;
};

struct planet
{
	int cost, a, b;
};

int parent[100001];
int N;

vector<X> vx;
vector<Y> vy;
vector<Z> vz;
vector<planet> pv;

bool comapare1(X a, X b)
{
	if (a.x < b.x)
		return true;
	if (a.x > b.x)
		return false;
	return false;
}

bool comapare2(Y a, Y b)
{
	if (a.y < b.y)
		return true;
	if (a.y > b.y)
		return false;
	return false;
}

bool comapare3(Z a, Z b)
{
	if (a.z < b.z)
		return true;
	if (a.z > b.z)
		return false;
	return false;
}

bool comapare4(planet a, planet b)
{
	if (a.cost < b.cost)
		return true;
	if (a.cost > b.cost)
		return false;
	return false;
}

int Find(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);
	
	if (pa == pb)
		return;

	parent[pb] = pa;
}



int main()
{
	cin >> N;
	int ans = 0;
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < N; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		vx.push_back({ x,i+1 });
		vy.push_back({ y,i + 1 });
		vz.push_back({ z,i + 1 });
	}

	sort(vx.begin(), vx.end(), comapare1);
	sort(vy.begin(), vy.end(), comapare2);
	sort(vz.begin(), vz.end(), comapare3);

	for (int i = 0; i < N - 1; i++)
	{
		pv.push_back({vx[i].x-vx[i+1].x,vx[i].idx,vx[i + 1].idx});
		pv.push_back({ vy[i].y - vy[i + 1].y,vy[i].idx,vy[i + 1].idx });
		pv.push_back({ vz[i].z - vz[i + 1].z,vz[i].idx,vz[i + 1].idx });
	}

	sort(pv.begin(), pv.end(), comapare4);
	for (int i = 0; i < pv.size(); i++)
	{
		int a = pv[i].a;
		int b = pv[i].b;
		
		if (Find(a) == Find(b))
			continue;

		Union(a, b);
		ans += pv[i].cost;
	}

	cout << ans;

}