#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	queue<int> q;
	vector<int> v;

	cin >> N >> K;

	for(int i = 1; i <= N; ++i)
	{
		q.push(i);
	}

	while(!q.empty())
	{
		for(int i = 0; i < K - 1; ++i)
		{
			q.push(q.front());
			q.pop();
		}
		v.push_back(q.front());
		q.pop();
	}

	cout << "<";
	for(int i = 0; i < v.size(); ++i)
	{
		cout << v[i];
		if (i != v.size() - 1)
			cout << ", ";
	}
	cout << ">";
}