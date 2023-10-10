#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int answer = 0;

	cin >> N;

	vector<int> A(N);
	vector<int> B;

	for(int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	B.push_back(A[0]);

	for(int i = 1; i < N; ++i)
	{
		if (B.back() < A[i])
			B.push_back(A[i]);
		else
			*lower_bound(B.begin(), B.end(), A[i]) = A[i];
	}
	cout << B.size();
}