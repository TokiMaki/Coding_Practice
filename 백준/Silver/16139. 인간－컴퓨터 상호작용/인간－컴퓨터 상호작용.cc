#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int alphanum[26][200001] = {0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string S;
	int q;
	cin >> S;
	alphanum[S[0] - 'a'][0] = 1;
	for (int i = 1; i < S.length(); ++i) {
		for (int j = 0; j < 26; ++j) {
			alphanum[j][i] = alphanum[j][i - 1];
		}
		alphanum[S[i] - 'a'][i] = alphanum[S[i] - 'a'][i - 1] + 1;
	}
	cin >> q;
	char alpha;
	int l, r;
	for (int i = 0; i < q; ++i) {
		cin >> alpha;
		cin >> l >> r;
		if (l > 0)
			cout << alphanum[alpha - 'a'][r] - alphanum[alpha - 'a'][l - 1] << "\n";
		else
			cout << alphanum[alpha - 'a'][r] << "\n";
	}
}