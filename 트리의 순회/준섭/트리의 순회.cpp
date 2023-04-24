#include <iostream>
#include <vector>

using namespace std;

vector<int> inorder;
vector<int> postorder;

// 인오더의 0번째 인덱스는 0번째 
int indexInorder[101010];

int n;

void preorder(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe) return;

	int root = postorder[pe];
	cout << root << " ";

	// 왼쪽부터
	preorder(is, indexInorder[root] - 1, ps, ps + (indexInorder[root] - is) - 1);

	// 오른쪽으로
	preorder(indexInorder[root] + 1, ie, ps + (indexInorder[root] - is), pe - 1);
}

int main() {
	// 프리오더 = 전위순회: 루트먼저 방문하고 왼쪽 그다음 오른쪽
	// 인오더 = 중위순회: 왼쪽과 오른쪽 서브트리 사이의 루트를 먼
	// 포스트오더 = 후위순회: 왼쪽과 오른쪽 서브트리를 다 방문 후

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		inorder.push_back(a);
	}

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		postorder.push_back(a);
	}

	for (int i = 0; i < n; i++) {
		indexInorder[inorder[i]] = i;
	}

	preorder(0, n - 1, 0, n - 1);
	return 0;
}