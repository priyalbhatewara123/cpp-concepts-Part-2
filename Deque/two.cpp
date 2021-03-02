/*
(2)
Problem Statement:
Find the length of longest substring with non-repeating characters.
It is a sliding window problem.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char a[] = "babbb";

	int n = strlen(a);
	int current_len = 1;
	int max_len = 1;

	//to keep track of the visited characters
	int visited[256];

	for (int i = 0; i < 256; i++) {
		visited[i] = -1;
	}
	//present at 0th index
	visited[a[0]] = 0;

	for (int i = 0; i < n; i++) {
		int last_occ = visited[a[i]];

		//expansion if there's no last occurence or it occured outside the window
		if (last_occ == -1 || i - current_len > last_occ) {
			current_len += 1;
		}
		//contraction + expansion
		else {
			current_len = i - last_occ;

		}

		if (current_len > max_len) {
			max_len = current_len;
		}
		visited[a[i]] = i;
	}

	cout << max_len;
}