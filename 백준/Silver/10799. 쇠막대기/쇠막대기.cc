#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;
	string raser;
	stack<char> s;

	cin >> raser;

	int stick = 0;

	for(char c : raser)
	{
		if (s.empty()) {
			s.push(c);
			continue;
		}
		if (c == '(')
		{
			if (s.top() == '(')
				stick++;
		}
		if (c == ')')
		{
			if (s.top() == '(')
				answer += stick;

			else if (s.top() == ')') {
				answer++;
				stick -= 1;
			}
		}
		s.push(c);
	}

	cout << answer;
}