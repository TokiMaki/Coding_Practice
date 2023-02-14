#include <iostream>
#include <map>

using namespace std;

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	map<string, int> m;
	for (int i = 0; i < T; ++i) {
		m.clear();
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			string name;
			string kind;
			cin >> name >> kind;
			m[kind]++;
		}

		int result = 1;
		for (auto a : m)
			result *= (a.second + 1);
		result -= 1;

		cout << result << "\n";
	}
}