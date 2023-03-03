#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<char> s;

	while (true) {
		bool answer = true;
		string tmp;
		getline(cin, tmp, '\n');

		if (tmp == ".")
			break;

		while (!s.empty())
			s.pop();

		for (char c : tmp) {
			if (c == '(' || c == '[')
				s.push(c);
			else if (!s.empty() && (c == ')' || c == ']')) {
				if (s.top() == '(' && c == ')') {
					s.pop();
				}
				else if (s.top() == '[' && c == ']') {
					s.pop();
				}
				else {
					answer = false;
					break;
				}
			}
			else if (c == ')' || c == ']') {
				answer = false;
				break;
			}
		}

		if (!s.empty())
			answer = false;

		if (answer)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';


	}
}