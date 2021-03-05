/*
(3)
BFS traversal with the help of queue.
This is more optimised approach as compared to recursion.
Time complexity: O(n)
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

//to print each level in single line
void bfs(node* root) {

	queue<node*> q;
	q.push(root); //push pointer to the node in queue

	while (!q.empty()) {
		node* f = q.front();
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

//to print each level in a different line
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
	bfs(root);

	cout << endl;
	cout << "Each level in different line:" << endl;
	bfsNewLine(root);

	return 0;
}