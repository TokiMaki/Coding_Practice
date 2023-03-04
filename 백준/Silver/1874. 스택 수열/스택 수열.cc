#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	stack<int> s;
	vector<int> v;
	vector<char> result;

	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	int vNum = 0;
	for (int i = 1; i <= n; ++i) {
		s.push(i);
		result.push_back('+');
		while (!s.empty() && s.top() == v[vNum] && vNum <= n) {
			s.pop();
			vNum++;
			result.push_back('-');
		}
	}

	if (!s.empty())
		cout << "NO";
	else {
		for (char c : result) {
			cout << c << '\n';
		}
	}
}