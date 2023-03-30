#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, Answer = 0;
	cin >> N;
	vector<int> A;
	vector<int> B;

	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		B.push_back(tmp);
	}

	sort(A.begin(), A.end(), less<int>());
	sort(B.begin(), B.end(), greater<int>());

	for (int i = 0; i < N; ++i) {
		Answer += A[i] * B[i];
	}

	cout << Answer;
}