#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, answer = 0;
	cin >> N;
	vector<int> v(N);		// first = start, second = end

	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int sum = 0;

	for (int i = 0; i < N; ++i) {
		answer += sum + v[i];
		sum += v[i];
	}

	cout << answer;
}