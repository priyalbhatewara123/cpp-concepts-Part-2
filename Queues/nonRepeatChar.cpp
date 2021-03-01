/*
(4)
First non repeating character in a running stream of characters
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	queue <char> q;

	//frequency map
	char freq[27] = {0};

	char ch; cin >> ch;
	//running stream till dot
	while (ch != '.') {

		//insert in queue
		q.push(ch);
		//update frequency array
		freq[ch - 'a']++;

		//query
		while (!q.empty()) {

			//find index in frequency table
			int index = q.front() - 'a';
			if (freq[index] > 1) {
				q.pop();
			}

			else {
				cout << q.front() << " ";
				break;
			}
		}

		if (q.empty())
			cout << -1 << " ";

		cin >> ch;
	}

	return 0;
}