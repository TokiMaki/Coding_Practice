#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> s;

	int K;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		int num;
		cin >> num;
		if (num == 0)
			s.pop();
		else
			s.push(num);
	}

	int answer = 0;
	while (s.empty() != true) {
		answer += s.top();
		s.pop();
	}

	cout << answer;
}