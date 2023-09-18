#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<pair<int, int>> dp(41);

pair<int, int> fibonacci(int n) {
	if (dp[n].first != -1 &&
		dp[n].second != -1)
	{
		return dp[n];
	}
	else {
		pair<int, int> n1 = fibonacci(n - 1);
		pair<int, int> n2 = fibonacci(n - 2);
		return dp[n] = { n1.first + n2.first, n1.second + n2.second };
	}
	
}

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < 41; ++i)
	{
		dp[i].first = -1;
		dp[i].second = -1;
	}

	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };
	for(int i = 0; i < T; ++i)
	{
		int temp;
		cin >> temp;
		fibonacci(temp);
		cout << dp[temp].first << " " << dp[temp].second << endl;
	}
}