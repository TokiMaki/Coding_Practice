#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	int num[10000] = {0, };

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		num[temp - 1]++;
	}

	for (int i = 0; i < 10000; ++i) {
		for (int j = 0; j < num[i]; ++j)
			cout << i + 1 << "\n";
	}
}