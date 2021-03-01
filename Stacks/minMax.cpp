/*
(9)
Min Max Stack:
Design a stack class that supports following operations.
- push() , pop()
- top()
- getMin()
- getMax()

We will solve with the help of vectors.
*/

#include<bits/stdc++.h>
using namespace std;

class minMaxStack {

	vector <int> stack;
	vector <int> min_stack;
	vector <int> max_stack;

public:
	int top() {
		return stack[stack.size() - 1];
	}

	void push(int data) {
		int currentMin = data;
		int currentMax = data;

		if (min_stack.size()) {
			currentMin = min(min_stack[min_stack.size() - 1] , data);
			currentMax = max(max_stack[max_stack.size() - 1] , data);
		}

		min_stack.push_back(currentMin);
		max_stack.push_back(currentMax);
		stack.push_back(data);
	}

	int getMin() {
		return min_stack[min_stack.size() - 1];
	}

	int getMax() {
		return max_stack[max_stack.size() - 1];
	}

	bool empty() {
		return stack.size() == 0;
	}

	void pop() {
		min_stack.pop_back();
		max_stack.pop_back();
		stack.pop_back();
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	minMaxStack s;
	s.push(1);
	s.push(5);
	s.push(3);
	s.push(8);

	cout << s.getMax() << endl;
	s.pop();
	cout << s.getMin() << endl;
	cout << s.getMax() << endl;

	s.pop();
	s.pop();

	cout << s.top() << endl;
	cout << s.getMax() << endl;

	return 0;
}