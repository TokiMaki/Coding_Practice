#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> v(N);

	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		v[i] = tmp;
	}

	int answer = 0;
	int i = N - 1;
	while (true) {
		if (K <= 0)
			break;
		else if (K >= v[i]) {
			K -= v[i];
			answer++;
		}
		else
			i--;
	}

	cout << answer;
}