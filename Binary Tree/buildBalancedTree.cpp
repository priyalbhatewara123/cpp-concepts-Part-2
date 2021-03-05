/*
(10)
Build a height balanced binary tree from an array.
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

node* buildBalancedTreeFromArray(int *a, int start , int end) {

	//base case
	if (start > end) {
		return NULL;
	}

	int mid = (start + end) / 2;
	node* root = new node(a[mid]);
	root -> left = buildBalancedTreeFromArray(a, start , mid - 1);
	root -> right = buildBalancedTreeFromArray(a, mid + 1 , end);

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

	int a[] = {1, 2, 3, 4, 5, 6, 7 , 8};
	int n = 8;

	node* root = buildBalancedTreeFromArray(a, 0, n - 1);
	bfsNewLine(root);

	return 0;
}