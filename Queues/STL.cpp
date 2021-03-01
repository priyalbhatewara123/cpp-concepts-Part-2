/*
(3)
STL Queue class:
push()
pop()
front()
empty()
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	queue <int> q;
	for (int i = 1; i <= 5; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}
