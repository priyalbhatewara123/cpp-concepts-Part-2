/*
(1)
Preorder built and print.
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

void print(node* root) {

	//base case
	if (root == NULL)
		return;

	//print root first then left children and then right children
	cout << root -> data << " ";
	print(root -> left);
	print(root -> right);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = buildTree();
	print(root);
}