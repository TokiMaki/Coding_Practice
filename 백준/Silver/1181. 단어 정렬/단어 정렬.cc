#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	//백준 입출력 속도 개선
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<string> v;

	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), [&](string a, string b) {
		if (a.length() == b.length())
			return a < b;
		else
			return a.length() < b.length();
		});

	v.erase(unique(v.begin(), v.end()), v.end());

	for (string s : v) {
		cout << s << "\n";
	}
}