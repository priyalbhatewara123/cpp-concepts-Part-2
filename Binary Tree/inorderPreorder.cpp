/*
(11)
Build a tree from Inorder and Preorder traversal.
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

node* createTreeFromTrav(int* in , int* pre , int start , int end) { //start and end index are for inorder traversal

	static int i = 0;
	/*
	i will keep track of index in preorder array.
	It is static as it needs to be declared only once and
	retain it's value in recursive calls.
	*/

	//base case
	if (start > end)
		return NULL;

	//recursive case
	node* root = new node(pre[i]);
	//find index of pre[i] in inorder array
	int index = -1;
	for (int j = start; j <= end; j++) {
		if (in[j] == pre[i]) {
			index = j;
			break;
		}
	}
	i++; //increment i before next call

	root -> left = createTreeFromTrav(in , pre , start , index - 1);
	root -> right = createTreeFromTrav(in , pre , index + 1 , end);

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

	int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
	int pre[] = {1 , 2, 3, 4, 8, 5, 6, 7};
	int n = 8;
	node* root = createTreeFromTrav(in , pre , 0 , n - 1);
	bfsNewLine(root);

	return 0;
}