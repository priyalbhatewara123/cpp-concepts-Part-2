/*
(1)
Implementing Circular Queue using array.
*/

#include<bits/stdc++.h>
using namespace std;

class Queue {

	int *arr;
	int front , rear , currentSize , maxSize;

public:

	Queue(int defaultSize) {
		arr = new int[defaultSize];
		currentSize = 0;
		maxSize = defaultSize;
		front = 0;
		rear = maxSize - 1;
	}

	bool full() {
		return currentSize == maxSize;
	}

	void push(int data) {
		if (!full()) {
			rear = (rear + 1) % maxSize;
			arr[rear] = data;
			currentSize++;
		}
	}

	bool empty() {
		return currentSize == 0;
	}

	void pop() {
		if (!empty()) {
			front = (front + 1) % maxSize;
			currentSize--;
		}
	}

	int frontElement() {
		if (!empty()) {
			return arr[front];
		}
	}

	~Queue() {
		if (arr != NULL) {
			delete [] arr;
			arr = NULL;
		}
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Queue q(10);

	for (int i = 1; i <= 8; i++) {
		q.push(i);
	}

	q.pop();
	q.pop();

	q.push(9);

	while (!q.empty()) {
		cout << q.frontElement() << " ";
		q.pop();
	}

	return 0;
}