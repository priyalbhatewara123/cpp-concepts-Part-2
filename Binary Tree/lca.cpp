/*
(14)
Lowest Common Ancestor (LCA)
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

node* lca(node* root , int a , int b) {

	//base case
	if (root == NULL)
		return NULL;

	if (root -> data == a or root -> data == b)
		return root;

	node* leftAns = lca(root -> left , a, b);
	node* rightAns = lca(root -> right , a, b);

	if (leftAns != NULL and rightAns != NULL)
		return root;

	if (leftAns != NULL)
		return leftAns;

	return rightAns;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = buildTree();
	int a, b; cin >> a >> b;

	cout << (lca(root , a, b) -> data);
	return 0;
}