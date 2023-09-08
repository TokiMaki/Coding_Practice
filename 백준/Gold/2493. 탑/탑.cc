#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	vector<int> answer;
	int N;
	vector<int> v;
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	stack<pair<int, int>> s;
	s.emplace(1, v[0]);
	answer.push_back(0);
	for(int i = 1; i < N; ++i)
	{
		while (!s.empty())
		{
			if (v[i] <= s.top().second)
			{
				answer.push_back(s.top().first);
				break;
			}
			else
				s.pop();
		}
		if (s.empty()) 
			answer.push_back(0);
		s.emplace(i + 1, v[i]);
	}
	for (int i : answer)
		cout << i << " ";
}