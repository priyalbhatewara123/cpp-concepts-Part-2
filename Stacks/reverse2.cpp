/*
(5)
Reverse stack using recursion: (implicit call stack)
(Video link: https://www.youtube.com/watch?v=pX5fzRIrJmA&feature=emb_logo)
*/

#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s , int x) {

	//base case
	if (s.empty()) {
		s.push(x);
		return;
	}

	//recursive case
	int y = s.top();
	s.pop();
	insertAtBottom(s, x);

	s.push(y);
}

void reverseStack(stack<int> &s) {

	//base case
	if (s.empty())
		return;

	//recursive case
	//pop out the top element and insert it at the bottom of 'reversed smaller stack'
	int x = s.top();
	s.pop();

	//recursively reverse the smaller stack
	reverseStack(s);

	insertAtBottom(s, x);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	reverseStack(s);
	cout << "Reversed Stack: ";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
