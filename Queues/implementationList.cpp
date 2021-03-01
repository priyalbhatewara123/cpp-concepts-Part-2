/*
(2)
Implementation using Linked list STL.
List STL supports insertion and deletion both at front and tail.
List class has the following methods:
	push_front()
	push_back()
	pop_front()
	pop_back()
*/

#include<bits/stdc++.h>
using namespace std;

class Queue {

	int currentSize;
	list <int> l;

public:
	Queue() {
		currentSize = 0;
	}

	bool isEmpty() {
		return currentSize == 0;
	}

	void push(int data) {
		l.push_back(data);
		currentSize = currentSize + 1;
	}

	void pop() {
		if (!isEmpty()) {
			l.pop_front();
			currentSize = currentSize - 1;
		}
	}

	int front() {
		return l.front();
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Queue q;
	for (int i = 1; i <= 10; i++) {
		q.push(i);
	}

	while (!q.isEmpty()) {
		cout << q.front() << " ";
		q.pop();
	}
}
