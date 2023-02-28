#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	int answer = 0;
	string s;
	cin >> s;

	vector<char> oper;
	vector<int> num;

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '+' || s[i] == '-') {
			oper.push_back(s[i]);
			s[i] = ' ';
		}
	}

	stringstream stream;
	stream.str(s);

	int tmp;
	while (stream >> tmp) {
		num.push_back(tmp);
	}

	answer += num[0];
	bool isminus = false;
	for (int i = 1; i < num.size(); ++i) {
		if (isminus == true) {
			answer -= num[i];
		}
		else if (oper[i - 1] == '+')
			answer += num[i];
		else {
			isminus = true;
			answer -= num[i];
		}
	}

	cout << answer;
}