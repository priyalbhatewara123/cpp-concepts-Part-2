/*
(5)
Implement Stack using 2 queue:
	push() - O(1)
	pop()  - O(N)
	top()  - O(N)
	empty()- 0(1)
	size() - 0(1)
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>

class Stack {

	queue <T> q1 , q2;
	/*
	One queue will always remain empty. Here we will push elements in q1
	and q2 will remain empty.
	*/
public:

	void push(T data) {
		q1.push(data);
	}

	void pop() {

		//remove last element from q1
		//first move n-1 elements in q2
		if (q1.empty()) {
			return;
		}

		while (q1.size() > 1) {
			T frontElement = q1.front();
			q2.push(frontElement);
			q1.pop();
		}

		//pop out the last element
		q1.pop();

		//interchange names of q1 and q2
		swap(q1, q2);
	}

	T top() {
		if (q1.empty()) {
			return -1;
		}

		while (q1.size() > 1) {
			T frontElement = q1.front();
			q2.push(frontElement);
			q1.pop();
		}

		T frontElement = q1.front();
		q1.pop();
		q2.push(frontElement);

		swap(q1, q2);

		return frontElement;
	}

	int size() {
		return q1.size();
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

	Stack <int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	cout << s.size();
	cout << endl;

	cout << s.top();
	cout << endl;

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}