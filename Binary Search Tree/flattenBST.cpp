/*
(5)
Convert a BST to sorted Linked List i.e Fatten a tree.
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

class LinkedList {
public:
	node* head;
	node* tail;
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

LinkedList flatten(node* root) {

	LinkedList l;
	//if root is NULL
	if (root == NULL) {
		l.head = l.tail = NULL;
		return l;
	}

	//leaf node
	if (root -> left == NULL and root -> right == NULL) {
		l.head = l.tail = root;
		return l;
	}

	//left subtree is not NULL but right subtree is NULL
	if (root -> left != NULL and root -> right == NULL) {
		LinkedList leftLL = flatten(root -> left);
		leftLL.tail -> right = root;

		l.head = leftLL.head;
		l.tail = root;

		return l;
	}

	//right subtree is not null and left is null
	if (root -> left == NULL and root -> right != NULL) {
		LinkedList rightLL = flatten(root -> right);
		root -> right = rightLL.head;

		l.head = root;
		l.tail = rightLL.tail;

		return l;
	}

	//both subtrees are not NULL
	LinkedList leftLL = flatten(root -> left);
	LinkedList rightLL = flatten(root -> right);

	leftLL.tail -> right = root;
	root -> right = rightLL.head;

	l.head = leftLL.head;
	l.tail = rightLL.tail;

	return l;
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

	LinkedList ll = flatten(root);
	node* temp = ll.head;

	while (temp != NULL) {
		cout << temp -> data << " -> ";
		temp = temp -> right;
	}

	return 0;
}