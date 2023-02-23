#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	vector<int> maxv(N);
	vector<int> rmaxv(N);
	int answer = 1;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		v[i] = tmp;
	}
	maxv[0] = 1;
	for (int i = 1; i < N; ++i) {
		maxv[i] = 1;
		for (int j = i - 1; j >= 0; --j) {
			if (v[i] > v[j])
				maxv[i] = max(maxv[i], maxv[j] + 1);
		}
	}
	rmaxv[N - 1] = 1;
	for (int i = N - 2; i >= 0; --i) {
		rmaxv[i] = 1;
		for (int j = i + 1; j < N; ++j) {
			if (v[i] > v[j])
				rmaxv[i] = max(rmaxv[i], rmaxv[j] + 1);
		}
	}

	for (int i = 0; i < N; ++i) {
		answer = max(answer, maxv[i] + rmaxv[i] - 1);
	}
	cout << answer;
}