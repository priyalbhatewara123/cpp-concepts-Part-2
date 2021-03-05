/*
(8)
Replace each node by sum of child nodes. Don't change the leaf nodes.
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

int replaceSum(node* root) {

	if (root == NULL)
		return 0;

	//leaf node
	if (root -> left == NULL and root-> right == NULL)
		return root -> data;

	//recursive part
	int leftSum = replaceSum(root -> left);
	int rightSum = replaceSum(root -> right);

	int temp = root -> data;
	root -> data = leftSum + rightSum;

	return temp + root -> data;
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

	node* root = buildTree();
	bfsNewLine(root);
	cout << endl;
	cout << endl;
	replaceSum(root);
	bfsNewLine(root);

	return 0;
}