#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp(1001);

int main() {
	int N;
	cin >> N;

	vector<int> v;

	for(int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	dp[0] = 1;
	for(int i = 1; i < N; ++i)
	{
		dp[i] = 1;
		for(int j = i - 1; j >= 0; --j)
		{
			if (v[i] < v[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	cout << *max_element(dp.begin(), dp.end());
}