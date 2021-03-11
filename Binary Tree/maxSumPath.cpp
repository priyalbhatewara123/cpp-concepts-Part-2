/*
(15)
Find maximum sum path from any node to any node in given binary tree.
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
	int branchSum;
	int maxSum;

	Pair() {
		branchSum = 0;
		maxSum = 0;
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

Pair maxSumPath(node* root) {
	Pair p;

	//base case
	if (root == NULL)
		return p;

	Pair left = maxSumPath(root -> left);
	Pair right = maxSumPath(root -> right);

	//four cases are possible while calculating max sum path through root
	int op1 = root -> data;
	int op2 = root -> data + left.branchSum + right.branchSum;
	int op3 = root -> data + left.branchSum;
	int op4 = root -> data + right.branchSum;

	int current_ans_through_root = max(op1, max(op2, max(op3 , op4)));

	p.branchSum = max(left.branchSum , max(right.branchSum , 0)) + root -> data; //0 for negative cases

	p.maxSum = max(left.maxSum , max(right.maxSum , current_ans_through_root));

	return p;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = buildTree();

	cout << "Maximum Sum Path : " << maxSumPath(root).maxSum ;
}