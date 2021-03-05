/*
(6)
Find the diameter of tree.
Worst case time complexity of this method is O(n2).
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

int height(node* root) {

	//base case
	if (root == NULL)
		return 0;

	return (max(height(root -> left) , height(root -> right)) + 1);
}

int diameter(node* root) {

	//base case
	if (root == NULL)
		return 0;

	int h1 = height(root -> left);
	int h2 = height(root -> right);
	int option1 = h1 + h2;
	int option2 = height(root->left);
	int option3 = height(root->right);

	return max(option1 , max(option2 , option3));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = buildTree();

	cout << "Diameter of tree is: ";
	cout << diameter(root);
	return 0;
}