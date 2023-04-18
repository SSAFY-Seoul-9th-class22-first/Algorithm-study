#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};
int sz;
// a->b 는(*a).b 과 동일하다
Node* insert(Node* node, int data) {
	if (node == NULL) {
		node = new Node();
		node->data = data;
		node->left = node->right = NULL;
	}
	else if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	return node;
}

void postorder(Node* node) {
	if (node->left != NULL)
		postorder(node->left);
	if (node->right != NULL)
		postorder(node->right);
	cout << node->data << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Node* root = NULL;
	int num;
	for (; cin >> num; ++sz) {
		root = insert(root, num);
	}
	postorder(root);
	return 0;
}
