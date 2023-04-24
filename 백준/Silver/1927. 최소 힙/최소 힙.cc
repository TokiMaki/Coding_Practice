#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		int tmp;
		cin >> tmp;
		if (tmp == 0)
		{
			if (pq.empty())
			{
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(tmp);
		}
	}
}