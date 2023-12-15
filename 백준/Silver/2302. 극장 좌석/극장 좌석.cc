#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(41);

int main() {
	int N, M;
	int answer = 1;
	cin >> N >> M;
	vector<int> seats;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 0; i < M; ++i)
	{
		int temp;
		cin >> temp;
		seats.push_back(temp);
	}

	for (int i = 3; i <= N; ++i)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	int start = 0;
	for (int seat : seats)
	{
		int end = seat;
		answer *= dp[end - start - 1];
		start = end;
	}

	answer *= dp[N - start];

	
	cout << answer;
}