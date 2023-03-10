#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long seg[1000001];
vector<long long> v(100001);
int n;
long long ans = INT_MIN;

int init(int node, int start, int end) {
	if (start == end) 
		return seg[node] = start;
	int mid = (start + end) / 2;
	int left_index = init(2 * node, start, mid);
	int right_index = init(2 * node + 1, mid + 1, end);

	return seg[node] = 
		v[left_index] < v[right_index] ? left_index : right_index;
}

int query(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return -1;
	if (left <= start && end <= right)
		return seg[node];

	int mid = (start + end) / 2;
	int left_index = query(node * 2, start, mid, left, right);
	int right_index = query(node * 2 + 1, mid + 1, end, left, right);

	if (left_index == -1)
		return right_index;
	if (right_index == -1)
		return left_index;
	else return v[left_index] < v[right_index] ? left_index : right_index;
}

void solve(long long left, long long right) {
	if (left > right)
		return;

	long long index = query(1, 0, n - 1, left, right);

	ans = max(ans, v[index] * (right - left + 1));

	solve(left, index - 1);
	solve(index + 1, right);
}

int main() {
	while (true) {
		cin >> n;
		if (n == 0)
			break;

		for (int i = 0; i < n; ++i) {
			int tmp;
			cin >> tmp;
			v[i] = tmp;
		}

		init(1, 0, n - 1);

		solve(0, n - 1);
		cout << ans << endl;
	}
}