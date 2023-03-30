#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int N;
	long long Answer = 0;
	priority_queue<long long, vector<long long>, greater<long long>> Pq;

	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		long long tmp;
		cin >> tmp;
		Pq.push(tmp);
	}
	while (Pq.size() > 1)
	{
		int a = Pq.top();
		Pq.pop();
		int b = Pq.top();
		Pq.pop();
		Answer += a + b;
		Pq.push(a + b);
	}

	cout << Answer;
}