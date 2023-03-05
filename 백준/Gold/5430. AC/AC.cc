#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		deque<int> d;

		string fuc;
		cin >> fuc;

		int n;
		cin >> n;

		string Array;
		cin >> Array;

		// stringstream을 위한 양식에 맞는 가공
		Array.erase(0, 1);
		Array.erase(Array.size() - 1, 1);
		replace(Array.begin(), Array.end(), ',', ' ');

		stringstream stream;
		stream.str(Array);
		int num;

		while (stream >> num)
			d.push_back(num);

		bool reverse = false;
		bool error = false;

		for (char c : fuc) {
			if (c == 'R') {
				reverse = 1 - reverse;
				continue;
			}
			else if (c == 'D') {
				if (d.empty()) {
					cout << "error" << '\n';
					error = true;
					break;
				}
				if (!reverse) 
					d.pop_front();
				else
					d.pop_back();
			}
		}

		if (!error) {
			if (!reverse) {
				cout << "[";
				for (auto it = d.cbegin(); it != d.cend(); ++it) {
					cout << *it;
					if (it + 1 != d.cend())
						cout << ",";
				}
				cout << "]" << '\n';
			}
			else {
				cout << "[";
				for (auto it = d.crbegin(); it != d.crend(); ++it) {
					cout << *it;
					if (it + 1 != d.crend())
						cout << ",";
				}
				cout << "]" << '\n';
			}
		}

		stream.str(Array);
	}
	
}