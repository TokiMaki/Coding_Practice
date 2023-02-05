#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;

	for (int i = 0; i < 5; ++i) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	int average = 0;
	int median = 0;

	int sum = 0;

	for (int i : v) {
		sum += i;
	}
	average = sum / 5;
	median = v[2];

	cout << average << endl;
	cout << median << endl;
}