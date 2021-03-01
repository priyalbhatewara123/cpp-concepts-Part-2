/*
(3)
Stack STL provides these methods:
	push()
	pop()
	top()
	empty()
Complexity of each method is O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	stack<char> s;
	//Stack<char , int> s;
	for (int i = 65; i <= 70; i++) {
		s.push(i);
	}

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}