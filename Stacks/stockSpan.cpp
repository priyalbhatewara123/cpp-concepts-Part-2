/*
(7)
Stock Span problem
(Video link: https://www.youtube.com/watch?v=29Jn5xPGJHg&feature=emb_logo)
*/

#include<bits/stdc++.h>
using namespace std;

void stockSpan(int prices[] , int n , int span[]) {

	//stack to store index
	stack <int> s;
	s.push(0);

	span[0] = 1;

	//loop for rest of the days
	for (int i = 1; i < n; i++) {

		int currentPrice = prices[i];
		while (!s.empty() and prices[s.top()] <= currentPrice) {
			s.pop();
		}
		if (!s.empty()) {
			int prevHighest = s.top();
			span[i] = i - prevHighest;
		}
		else {
			span[i] = i + 1;
		}

		//push this element into the stack
		s.push(i);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int prices[] = {10, 80, 60, 70, 60, 75, 85};
	int n = sizeof(prices) / sizeof(int);
	int span[10] = {0};

	stockSpan(prices , n , span);

	for (int i = 0; i < n; i++) {
		cout << span[i] << " ";
	}
	return 0;
}

//Overall complexity is O(n) as each element is pushed and poped only once.