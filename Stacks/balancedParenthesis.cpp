/*
(6)
Balanced Parenthesis:
Check if the expression is valid or not.

))(( Here no of opening brackets is equal to closing brackets but they are
not balanced and expression is not valid.

(Video link: https://www.youtube.com/watch?v=EccYp6GERGQ&feature=emb_logo)
*/

#include<bits/stdc++.h>
using namespace std;

bool isValidExp(char *s) {

	stack<char> stk;

	for (int i = 0; s[i] != '\0'; i++) {

		char ch = s[i];
		if (ch == '(')
			stk.push(ch);

		else if (ch == ')') {
			if (stk.empty() or stk.top() != '(')
				return false;

			stk.pop();
		}
	}

	return stk.empty();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char ch[] = "((a+b) + (c-d+f))";

	if (isValidExp(ch))
		cout << "Expression is valid!";

	else
		cout << "Expression is not valid!";

	return 0;
}