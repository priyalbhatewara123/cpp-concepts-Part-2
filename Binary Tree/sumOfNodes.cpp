/*
(5)
Print sum of all nodes.
Complexity: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree() {

	int d; cin >> d;
	//base case
	if (d == -1)
		return NULL;

	node* root = new node(d);
	root -> left = buildTree();
	root -> right = buildTree();

	return root;
}

int nodesSum(node* root) {

	//base case
	if (root == NULL)
		return 0;

	//preorder traversal
	return (root->data + nodesSum(root -> left) + nodesSum(root -> right));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = buildTree();
	cout << nodesSum(root);

	return 0;
}