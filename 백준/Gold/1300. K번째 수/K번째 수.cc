#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long  N, k;

void my_binary_search()
{
	long long left = 1, right = N * N;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for(int i = 1; i <= N; ++i)
		{
			cnt += min(mid / i, N);
		}
		if (cnt >= k)
			right = mid - 1;
		else
			left = mid + 1;
	}
	cout << left;
}

int main()
{
	cin >> N >> k;
	my_binary_search();
}