#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;

int main()
{
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	vector<int> v;

	v.push_back(A[0]);

	for(int i = 1; i < N; ++i)
	{
		if (v.back() < A[i])
			v.push_back(A[i]);
		else {
			auto iter = lower_bound(v.begin(), v.end(), A[i]);
			*iter = A[i];
		}
	}

	cout << v.size();
}