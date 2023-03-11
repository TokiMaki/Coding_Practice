#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long maxReturnValue = INT_MIN;

long long  binary_cut(vector<int> v, int N, long long  startcutlength, long long  endcutlength) {
	int cnt = 0;
	if (startcutlength > endcutlength)
		return maxReturnValue;
	long long cutlength = (startcutlength + endcutlength) / 2;
	for (int i : v)
		cnt += (i / cutlength);
	if (cnt >= N) {
		maxReturnValue = max(maxReturnValue, cutlength);
		return binary_cut(v, N, cutlength + 1, endcutlength);
	}
	else {
		return binary_cut(v, N, startcutlength, cutlength - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	int K, N;
	cin >> K >> N;
	for (int i = 0; i < K; ++i) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	maxReturnValue = INT_MIN;
	
	cout << binary_cut(v, N, 1, *max_element(v.cbegin(), v.cend()));
}