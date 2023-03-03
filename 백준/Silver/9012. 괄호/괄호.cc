#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	stack<char> s;


	for (int i = 0; i < T; ++i) {
		bool answer = true;
		string tmp;
		cin >> tmp;

		while (!s.empty())
			s.pop();

		for (char c : tmp) {
			if (c == '(')
				s.push(c);
			else if (!s.empty())
				s.pop();
			else {
				answer = false;
				break;
			}
		}

		if (!s.empty())
			answer = false;

		if (answer)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}