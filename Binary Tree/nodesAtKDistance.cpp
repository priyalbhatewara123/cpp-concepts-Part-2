/*
(13)
Print all nodes at distance k from given target node.
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

//to print all nodes present at kth level
void printKthLevel(node* root , int k) {

	//base case
	if (root == NULL)
		return;

	if (k == 0) {
		cout << root -> data << " ";
		return;
	}

	printKthLevel(root -> left , k - 1);
	printKthLevel(root -> right , k - 1);
}

int nodeAtKDistance(node* root , node* target , int k) {

	//base case
	if (root == NULL)
		return -1;

	//reach the target node
	if (root == target) {
		printKthLevel(target , k);
		return 0;
	}

	//ancestor
	int DL = nodeAtKDistance(root -> left , target , k);

	if (DL != -1) {
		//again 2 cases
		//ancecstor itself or you need to go to the right ancecstor
		if (DL + 1 == k) {
			cout << root -> data << " ";
		}

		else {
			printKthLevel(root -> right , k - 2 - DL);
		}
		return 1 +  DL;
	}

	int DR = nodeAtKDistance(root -> left , target , k);

	if (DR != -1) {
		//again 2 cases
		//ancecstor itself or you need to go to the right ancecstor
		if (DR + 1 == k) {
			cout << root -> data << " ";
		}

		else {
			printKthLevel(root -> left , k - 2 - DR);
		}
		return 1 +  DR;
	}

	return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = buildTree();
	node* target = root -> left -> left;

	int k; cin >> k;

	nodeAtKDistance(root , target, k);
	return 0;
}