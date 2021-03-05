/*
(9)
Check if the tree is height balanced tree or not.
Time Complexity: O(n)
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

class HBPair {
public:
	int height;
	bool balanced;
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

HBPair isHeightBalanced(node* root) {

	HBPair p;

	if (root == NULL) {
		p.height = 0;
		p.balanced = true;
		return p;
	}

	//recursive case (post-ordered traversal)
	HBPair left = isHeightBalanced(root -> left);
	HBPair right = isHeightBalanced(root -> right);

	p.height = max(left.height , right.height) + 1;
	if (abs(left.height - right.height) <= 1 and left.balanced and right.balanced) {
		p.balanced = true;
	}
	else {
		p.balanced = false;
	}

	return p;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = buildTree();
	if (isHeightBalanced(root).balanced) {
		cout << "The tree is balanced.";
	}

	else {
		cout << "The tree is not balanced.";
	}

	return 0;
}