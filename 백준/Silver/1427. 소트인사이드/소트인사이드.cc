#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	string N;
	cin >> N;
	vector<int> v;

	for (int i = 0; i < N.length(); ++i) {
		v.push_back(N[i] - 48);
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i : v)
		cout << i;
}