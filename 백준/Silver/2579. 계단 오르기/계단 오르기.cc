#include <iostream>
#include <vector>

using namespace std;

int dp[301];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;

	int N;
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	dp[0] = v[0];
	dp[1] = v[0] + v[1];
	dp[2] = max(v[0] + v[2], v[1] + v[2]);
	for(int i = 3; i < N; ++i)
	{
		dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
	}
	cout << dp[N - 1];
}