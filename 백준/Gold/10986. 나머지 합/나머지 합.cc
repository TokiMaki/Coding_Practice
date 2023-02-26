#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<long long> cnt(M, 0);

	long long sum = 0, answer = 0;

	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		sum += tmp;
		sum %= M;
		cnt[sum]++;
	}
	
	answer += cnt[0];

	for (int i = 0; i < M; ++i) {
		answer += ((cnt[i] * (cnt[i] - 1)) / 2);
	}
	cout << answer;
}