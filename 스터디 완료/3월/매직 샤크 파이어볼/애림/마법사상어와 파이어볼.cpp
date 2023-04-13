#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct fireball {
	int r, c, m, s, d;
};

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };


int even_Dir[] = { 0, 2, 4, 6 };
int odd_Dir[] = { 1, 3, 5 ,7 };

vector <fireball> map[51][51];
vector<pair<int, int>> v;
int N, M, K;

bool check(int y,int x)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (y == v[i].first && x == v[i].second)
			return false;
	}
	return true;
}
void move()
{
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int flag = 0;
			if (check(i, j))
			{
				for (int k = 0; k < map[i][j].size(); k++)
				{
					cout << "i,j " << i << " " << j << endl;
					fireball ball = map[i][j][k];
					int m = ball.m;
					int s = ball.s;
					int d = ball.d;
					int r = ball.r;
					int c = ball.c;

					int nr = (r + dy[d] * s) % N;
					int nc = (c + dx[d] * s) % N;

					if (nr > N)
						nr -= N;
					if (nc > N)
						nc -= N;
					if (nr < 1)
						nr += N;
					if (nc < 1)
						nc += N;

					cout << "nr,nc " << nr << " " << nc << endl;
					if (!(nr == i && nc == j))
						map[nr][nc].push_back({ nr,nc,m,s,d }); //이동해주기
					v.push_back({ nr,nc });
					if (nr == i && nc == j)
						flag = 1;
				}
				if(flag==0)
					map[i][j].clear();//이동해줬으니까 기존 좌표에 있는 볼들 지워주기
			}
			
		}

	}

	v.clear();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << map[i][j].size() << " ";
		

		}cout << endl;
	}
}

void merge()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j].size() > 1)
			{
				int sm=0, sd=0, ss=0;
				int flag = 0; //0이면 짝수
				vector<fireball> mergeBall;
				for (int k = 0; k < map[i][j].size(); k++)
				{
					fireball ball = map[i][j][k];
					int m = ball.m;
					int s = ball.s;
					int d = ball.d;
					int r = ball.r;
					int c = ball.c;

					sm += m;
					ss += s;
					if (flag==0 && d % 2 == 1)
					{
						flag = 1;//홀수가 하나라도 있음
					}

					
				}

				sm /= 5;
				ss /= map[i][j].size();
				
				map[i][j].clear();
				if (sm != 0) //질량이 0이 아니면 어차피 나눠지니까 0이면 단체로 push 안해주면 되징낳나?
				{
					for (int k = 0; k < 4; k++)
					{
						if (flag == 0)
							map[i][j].push_back({ i,j,sm,ss,even_Dir[k] });
						else
							map[i][j].push_back({ i,j,sm,ss,odd_Dir[k] });
					}
				}
			
			}

			
			
		}

	}
}

int main()
{

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++)
	{
		int r, c, m, d, s;
		cin >> r >> c >> m >> s >> d;
		map[r][c].push_back({ r,c,m,s,d });

	}
	for (int i = 0; i < K; i++)
	{
		move();
		merge();
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << map[i][j].size()<<" ";
			for (int k = 0; k < map[i][j].size(); k++)
			{
				ans += map[i][j][k].m;
			}
			
		}cout << endl;
	}

	cout << ans;
	return 0;

}