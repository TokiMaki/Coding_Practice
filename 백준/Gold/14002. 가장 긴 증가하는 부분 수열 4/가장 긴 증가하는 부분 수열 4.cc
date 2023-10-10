#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	int answer = 0;

	cin >> N;

	vector<int> A(N);
	vector<vector<int>> dp(N);

	for(int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	
	dp[0].push_back(A[0]);

	for(int i = 1; i < N; ++i)
	{
		dp[i].push_back(A[i]);
		for (int j = i - 1; j >= 0; --j) {
			if (A[i] > A[j])
			{
				if (dp[i].size() < dp[j].size() + 1)
				{
					vector<int> temp = dp[j];
					temp.push_back(A[i]);
					dp[i] = temp;
				}
			}
		}
	} 
	int maxSize = 1;
	int maxIdx = 0;
	for(int i = 0; i < N; ++i)
	{
		if (maxSize < static_cast<int>(dp[i].size())) {
			maxSize = dp[i].size();
			maxIdx = i;
		}
	}

	cout << maxSize << endl;
	for (int i : dp[maxIdx])
		cout << i << " ";
}