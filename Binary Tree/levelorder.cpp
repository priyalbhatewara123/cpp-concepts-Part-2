/*
(2)
Level order traversal:
Worst time complexity: O(n2)
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

//height from a node = max(height of left child , height of right child) + 1
int height(node* root) {

	//base case
	if (root == NULL)
		return 0;

	return (max(height(root -> left) , height(root -> right)) + 1);
}

//to print all nodes present at kth level
void printKthLevel(node* root , int k) {

	//base case
	if (root == NULL)
		return;

	if (k == 1) {
		cout << root -> data << " ";
		return;
	}

	printKthLevel(root -> left , k - 1);
	printKthLevel(root -> right , k - 1);
}

//to print all levels
void printAllLevels(node* root) {

	int h = height(root);
	for (int i = 1; i <= h; i++) {
		printKthLevel(root , i);
		cout << endl;
	}

	return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = buildTree();
	//print(root);

	cout << height(root) << endl;

	//printKthLevel(root , 2);
	printAllLevels(root);
	return 0;
}