#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int N, M, K;

long long init(vector <long long> &arr, vector <long long> &tree, int node, int start, int end)
{
	if (start == end)
	{
		return tree[node] = arr[start];
	}
	else
		return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2) + init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

void update(vector <long long> &tree, int node, int start, int end, int idx, long long diff)
{
	if (idx<start || idx>end) return;
	tree[node] += diff;
	if (start != end)
	{
		update(tree, node * 2, start, (start + end) / 2, idx, diff);
		update(tree, node * 2+1, (start+end)/2+1, end, idx, diff);
	}

}

long long Sum(vector<long long>& tree, int node, int start, int end, int left, int right)
{
	if (right<start || left>end)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	else
		return Sum(tree, node * 2, start, (start + end) / 2, left, right) + Sum(tree, node * 2+1, (start + end) / 2 + 1, end, left, right);
}
int main()
{
	cin >> N >> M >> K;
	int h = (int)ceil(log2(N));
	//cout << "h :" << h << endl;
	int t_size = pow(h + 1, 2);
	vector <long long> arr(N);
	vector <long long> tree(t_size*10000);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	//세그먼트 트리는 1부터 인덱스 시작.
	init(arr, tree, 1, 0, N - 1);
	/*
	for (int i = 0; i < tree.size(); i++)
		cout << tree[i] << " ";
	cout << endl;
	*/
	for (int i = 0; i < M + K; i++)
	{
		int a, b, c;
		cin >> a;
		if (a == 1) //바꾸기 update
		{
			long long value;
			cin >> b >> value;
			long long diff = value-arr[b-1] ;
			arr[b-1] = value;
			update(tree,1, 0, N - 1, b-1, diff);
			/*
			for (int i = 0; i < tree.size(); i++)
				cout << tree[i] << " ";
			cout << endl;
			*/
		}
		else { //sum 
			cin >> b >> c;
			cout << Sum(tree, 1, 0, N - 1, b - 1, c - 1) << endl;
		}
	}

	
	return 0;
}