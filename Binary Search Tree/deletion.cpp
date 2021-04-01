/*
(3)
Delete a node from BST.

3 possible cases:
1. delete a node with 0 children
2. delete a node with 1 child
3. delete a node with 2 children
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

node* deleteInBST(node* root , int key) {

	if (root == NULL)
		return NULL;

	else if (key < root -> data) {
		root -> left = deleteInBST(root -> left , key);
		return root;
	}

	else if (key == root -> data) {
		//found node to delete - 3 cases possible

		//Case 1: node with 0 children
		if (root -> left == NULL and root -> right == NULL) {
			delete root;
			return NULL;
		}

		//Case 2: node with 1 child
		if (root -> left != NULL and root -> right == NULL) {
			node* temp = root -> left;
			delete root;
			return temp;
		}

		if (root -> left == NULL and root -> right != NULL) {
			node* temp = root -> right;
			delete root;
			return temp;
		}

		//Case 3: node with 2 children
		//here we will replace node to delete with the inorder successor
		node* replace = root -> right;
		while (replace -> left != NULL) {
			replace = replace -> left;
		}

		root -> data = replace -> data;
		root -> right = deleteInBST(root -> right , replace -> data);

		return root;
	}

	else {
		root -> right = deleteInBST(root -> right , key);
		return root;
	}
}

void bfsNewLine(node* root) {

	queue<node*> q;
	q.push(root); //push pointer to the node in queue
	q.push(NULL);

	while (!q.empty()) {

		node* f = q.front();

		if (f == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty())
				q.push(NULL);
		}
		else {

			cout << f -> data << " ";
			q.pop();

			if (f -> left) {
				q.push(f->left);
			}

			if (f -> right) {
				q.push(f->right);
			}
		}
	}

	return;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = build();

	bfsNewLine(root);
	cout << "After deletion: " << endl;

	int key; cin >> key;
	deleteInBST(root , key);
	bfsNewLine(root);
}