#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	deque<int> d;
	for (int i = 0; i < N; ++i) {
		string command;
		cin >> command;
		if (command == "push_front") {
			int x;
			cin >> x;
			d.push_front(x);
		}
		if (command == "push_back") {
			int x;
			cin >> x;
			d.push_back(x);
		}
		if (command == "pop_front") {
			if (d.empty()) 
				cout << -1 << '\n';
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		if (command == "pop_back") {
			if (d.empty())
				cout << -1 << '\n';
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		if (command == "size") {
			cout << d.size() << '\n';
		}
		if (command == "empty") {
			if (d.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		if (command == "front") {
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.front() << '\n';
		}
		if (command == "back") {
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.back() << '\n';
		}
	}
}