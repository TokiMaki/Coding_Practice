#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, C;
vector<int> dist;
int answer = INT_MIN;

void binary_search(int left, int right)
{
	if (left > right)
		return;
	int mid = (left + right) / 2;
	int cnt = 0;
	int before = -1;

	for(const int& i : dist)
	{
		if (before == -1 || before + mid <= i) {
			before = i;
			cnt++;
		}
	}

	if (cnt >= C) {
		if (answer < mid)
			answer = mid;
		binary_search(mid + 1, right);
	}
	else {
		binary_search(left, mid - 1);
	}
}

int main()
{
	cin >> N >> C;

	for(int i = 0; i < N; ++i)
	{
		int tmp;
		cin >> tmp;
		dist.push_back(tmp);
	}

	sort(dist.begin(), dist.end());

	binary_search(0, dist[dist.size() - 1]);

	cout << answer;
}