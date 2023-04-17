#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<set>

#define R first
#define C second
using namespace std;
using ll = long long;
using pii = pair<int, int>;


// 0 부모 1 left right
int tree[1000010][3];
int sz;
int flag;


// left 1/ right 2
void maketree(int root, int branch) {
    if (flag) return;
    if (root > branch) {
        if (!tree[root][1]) {
            tree[root][1] = branch;
            flag = 1;
            return;
        }
        maketree(tree[root][1], branch);
    }
    else {
        if (!tree[root][2]) {
            tree[root][2] = branch;
            flag = 1;
            return;
        }
        maketree(tree[root][2], branch);
    }
}

void postorder(int root) {
    if (tree[root][1]) {
        postorder(tree[root][1]);
        cout << tree[root][1] << "\n";
    }
    if (tree[root][2]) {
        postorder(tree[root][2]);
        cout << tree[root][2] << "\n";
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin.tie(NULL)->sync_with_stdio(false);
    int num;
    cin >> num;
    int root = num;
    tree[root][0] = 21e8;
    for (; cin >> num; ++sz) {
        flag = 0;
        maketree(root, num);
    }
    postorder(root);
    cout << root << "\n";

    return 0;
}
