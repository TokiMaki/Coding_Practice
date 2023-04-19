#include <iostream>
#include <vector>

using namespace std;

int starthigh = 1000000000;
long long answer = 0;

void my_binary_search(vector<long long> v, long long start, long long end, long long M)
{
	if (start > end)
		return;
	long long sum = 0;
	long long mid = (start + end) / 2;
	for (int i : v)
		if (i - mid > 0)
			sum += i - mid;
	if (M <= sum)
	{
		if (answer < mid)
			answer = mid;
		my_binary_search(v, mid + 1, end, M);
	}
	else
		my_binary_search(v, start, mid - 1, M);
}

int main()
{
	long long N, M;
	cin >> N >> M;
	vector<long long> trees(N);
	for(int i = 0; i < N; ++i)
	{
		cin >> trees[i];
	}
	my_binary_search(trees, 0, starthigh, M);
	cout << answer;
}