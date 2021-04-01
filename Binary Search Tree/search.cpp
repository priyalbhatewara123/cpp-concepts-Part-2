/*
(2)
Search an element in BST.
Time Complexity: O(height)
Best Case : O(logN)
In worst case O(n) when it is skew tree.
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

//accepts old root node and data and returns the new root node
node* insertInBST(node* root , int d) {

	//base case
	if (root == NULL)
		return new node(d);

	//recursive case - insert in subtree and update pointers
	if (d <= root -> data)
		root -> left = insertInBST(root->left , d);

	else {
		root -> right = insertInBST(root -> right , d);
	}
	return root;
}

node* build() {
	//read a list of numbers till -1 and insert it in BST
	int d; cin >> d;
	node* root = NULL;
	while (d != -1) {
		root = insertInBST(root , d);
		cin >> d;
	}
	return root;
}

bool search(node* root , int key) {

	//base case
	if (root == NULL)
		return false;

	if (root -> data == key)
		return true;

	//search recursively in left and right subtree
	if (key < root -> data) {
		return search(root -> left , key);
	}

	return search(root->right , key);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = build();
	int key; cin >> key;

	if (search(root , key)) {
		cout << "Node is present.";
	}

	else {
		cout << "Not present.";
	}

	return 0;
}