/*
(16)
Find the shortest distance between 2 nodes of a binary tree.

Approach: We will find with the help of lca.
Shortest distance between 2 nodes is sum of there distance from LCA.
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


//finding level of any node from a given node
int search(node* root , int key , int level) { //key is the node whose level we have to find

	if (root == NULL)
		return -1;

	if (root -> data == key)
		return level;

	int left = search(root -> left , key , level + 1);
	if (left != -1)
		return left;

	return search(root -> right , key , level + 1);
}

//function to find distance between 2 nodes
int distance(node* root , int a , int b) {
	node* lca_node = lca(root , a, b);

	int l1 = search(lca_node , a, 0);
	int l2 = search(lca_node , b, 0);

	return l1 + l2;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = buildTree();
	int a, b; cin >> a >> b;

	cout << "Distance is: " << distance(root , a , b);
	return 0;
}