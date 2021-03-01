/*
(6)
Implement Queue using 2 stacks
	push() - O(1)
	pop()  - O(N)
	front()- O(N)
	empty()- 0(1)
	size() - 0(1)
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>

class Queue {

	stack<T> s1 , s2;

public:

	void push(T data) {
		s1.push(data);
	}

	void pop() {
		//remove last element from s1
		//first move n-1 elements in s2
		if (s1.empty()) {
			return;
		}

		while (s1.size() > 1) {
			T topElement = s1.top();
			s2.push(topElement);
			s1.pop();
		}

		//pop out the last element
		s1.pop();

		while (s2.size() > 0) {
			T topElement = s2.top();
			s1.push(topElement);
			s2.pop();
		}
	}

	T front() {
		if (s1.empty()) {
			return -1;
		}

		while (s1.size() > 1) {
			T topElement = s1.top();
			s2.push(topElement);
			s1.pop();
		}

		T topElement1 = s1.top();
		s1.pop();
		s2.push(topElement1);

		while (s2.size() > 0) {
			T topElement = s2.top();
			s1.push(topElement);
			s2.pop();
		}

		return topElement1;
	}

	int size() {
		return s1.size() + s2.size();
	}

	bool empty() {
		return size() == 0;
	}

};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Queue <int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	cout << q.size();
	cout << endl;

	cout << q.front();
	cout << endl;

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	return 0;

}