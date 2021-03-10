/*
(12)
Right View of a Binary Tree:

Sample Test Case:
Input:
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1

Output:
1
2 3
4 5
6 7 8 9
10 11

Right View : 1 3 5 9 11

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

void printRightView(node* root , int level , int &maxLevel) {

	//base case
	if (root == NULL)
		return;

	if (maxLevel < level) {

		//this means we have discovered a new level
		cout << root -> data << " ";
		maxLevel = level;
	}

	printRightView(root -> right , level + 1 , maxLevel);
	printRightView(root -> left , level + 1 , maxLevel);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = buildTree();

	int maxLevel = -1;

	bfsNewLine(root);
	cout << endl;
	cout << "Right View : ";
	printRightView(root , 0 , maxLevel);

	return 0;
}