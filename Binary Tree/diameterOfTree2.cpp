/*
(7)
Find the diameter of tree.

Approach: Previous method took O(n) time to calculate height with was to be
calculated for n nodes , so total complexity is O(n2).
To optimise this we will do bottom up traversal(post-order) and store heights.
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

class Pair {
public:
	int height;
	int diameter;
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

Pair fastDiameter(node* root) {

	Pair p;
	if (root == NULL) {
		p.diameter = p.height = 0;
		return p;
	}

	Pair left = fastDiameter(root -> left);
	Pair right = fastDiameter(root -> right);

	p.height = max(left.height , right.height) + 1;
	p.diameter = max((left.height + right.height) , max(left.diameter , right.diameter)) ;

	return p;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = buildTree();
	Pair p = fastDiameter(root);
	cout << "Height of tree is: " << p.height << endl;
	cout << "Diameter of tree is: " << p.diameter ;

	return 0;
}