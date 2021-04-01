/*
(1)
Insertion in Binary Search Tree.
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
}