#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string S;
	set<string> s;
	cin >> S;

	for (int i = 0; i < S.length(); ++i) {
		string tmp = "";
		for (int j = i; j < S.length(); ++j) {
			tmp += S[j];
			s.insert(tmp);
		}
		tmp.clear();
	}

	cout << s.size();
}