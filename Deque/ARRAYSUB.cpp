/*
(1)
Problem Statement: https://www.spoj.com/problems/ARRAYSUB/
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n;
	int a[100];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> k;

	//we have to process 1st k elements seperately
	deque <int> Q(k);
	int i;
	for (i = 0; i < k; i++) {
		while (!Q.empty() and a[i] > a[Q.back()]) {
			Q.pop_back();
		}
		Q.push_back(i);
	}

	//process the remaining elements
	for (; i < n; i++) {
		cout << a[Q.front()] << " ";

		//contraction
		//1.remove the elements which are not a part of window
		while (!Q.empty() and (Q.front() <= i - k)) {
			Q.pop_front();
		}

		//2.remove elements which are not useful and are in window
		while (!Q.empty() and a[i] >= a[Q.back()]) {
			Q.pop_back();
		}

		//3. add new elements(expansion)
		Q.push_back(i);
	}

	cout << a[Q.front()];
	return 0;
}