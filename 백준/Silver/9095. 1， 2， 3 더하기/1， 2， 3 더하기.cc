#include <iostream>
#include <cmath>

using namespace std;

int dp[12] = {0, };

int main()
{
	int T;
	int num;
	cin >> T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for(int i = 0; i < T; ++i)
	{
		cin >> num;
		if (num >= 4)
		{
			if (dp[num] == 0) {
				{
					for (int i = 4; i <= num; ++i)
					{
						if (dp[i] == 0)
							dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
					}
				}
			}
		}
		cout << dp[num] << endl;
	}
}