#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int num[100001] = {0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		int tmp;
		cin >> tmp;
		num[i] = tmp + num[i - 1];
	}
	int answer = INT_MIN;
	for (int i = 1; i <= N; ++i) {
		int isumK = i + K - 1;
		if (isumK > N)
			break;
		answer = max(answer, num[isumK] - num[i - 1]);
	}
	cout << answer;
}