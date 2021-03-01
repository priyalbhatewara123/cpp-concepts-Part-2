/*
(4)
Reverse Stack using 1 extra stack (explicit)
(Video link: https://www.youtube.com/watch?v=HI-KhyHcMSE&feature=emb_logo)
*/

#include<bits/stdc++.h>
using namespace std;

//n is number of elements to be transferred
void transfer(stack<int> &source , stack<int> &dest , int n) {

	for (int i = 0; i < n; i++) {
		dest.push(source.top());
		source.pop();
	}
}

void reverseStack(stack<int> &s) {

	//helper stack
	stack <int> s1;
	int n = s.size();
	for (int i = 0; i < n; i++) {

		//pick the top element and insert it at the bottom
		int x = s.top();
		s.pop();

		//transfer n-i-1 elements from stack s to s1
		transfer(s, s1, n - i - 1);

		//insert element x in s
		s.push(x);

		//transfer n-i-1 elements from s1 to s
		transfer(s1 , s, n - i - 1);
	}
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