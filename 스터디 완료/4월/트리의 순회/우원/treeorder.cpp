#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n;
int inorder[100100];
int preorder[100100];
int postorder[100100];
int inidx[100100];

// in	->	left	/	root	/	right 
// pre	->	root	/	left	/	right
// post ->	left	/	right	/	root

void makepre(int ist, int ied, int pst, int ped) {
	if (ist > ied || pst > ped) return;
	int rootidx = inidx[postorder[ped]];
	int leftsize = rootidx - ist;

	cout << inorder[rootidx] << " ";
	makepre(ist, rootidx-1, pst, pst + leftsize - 1);
	makepre(rootidx + 1, ied, pst + leftsize, ped-1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> inorder[i];
		inidx[inorder[i]] = i;
	}
	for (int i = 0; i < n; ++i) cin >> postorder[i];
	makepre(0,n-1,0,n-1);

	return 0;
}
