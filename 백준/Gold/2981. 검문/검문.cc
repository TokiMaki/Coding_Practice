#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else
		gcd(b, a % b);
}


int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	auto minmax = minmax_element(v.cbegin(), v.cend());

	int maxminusmin = *minmax.second - *minmax.first;
	set<int> factorization;

	int i = 2;

	int sum = 0;

	factorization.insert(maxminusmin);

	for (int i = 2; i * i <= maxminusmin; i++) {
		if (maxminusmin % i == 0) {
			factorization.insert(i);
			factorization.insert(maxminusmin / i);
		}
	}

	for (int a : factorization) {
		bool succ = true;
		int remain = -1;
		for (int i : v) {
			if (remain == -1)
				remain = i % a;
			else if (remain != i % a) {
				succ = false;
				break;
			}
		}
		if (true == succ) {
			cout << a << " ";
		}
	}
}