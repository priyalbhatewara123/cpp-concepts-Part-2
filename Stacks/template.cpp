/*
(2)
Creating a Templated class Stack.
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
//template <typename T , typename U>

class Stack {

private:
	vector<T> v;
	//vector<U> v2;

public:
	void push(T data) {
		v.push_back(data);
	}

	bool isEmpty() {
		return (v.size() == 0);
	}

	void pop() {
		if (!isEmpty()) {
			v.pop_back();
		}
	}

	T top() {
		return v[v.size() - 1];
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Stack<char> s;
	//Stack<char , int> s;
	for (int i = 65; i <= 70; i++) {
		s.push(i);
	}

	while (!s.isEmpty()) {
		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}