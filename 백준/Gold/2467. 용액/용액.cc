#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<int> v(100001);

int main() {
	int N;
	vector<int> answer;
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	int s = 0;
	int e = N - 1;
	int minResult = INT_MAX;

	while(s < e)
	{
		int result = abs(v[s] + v[e]);
		if (minResult > result) {
			answer.clear();
			answer.push_back(v[s]);
			answer.push_back(v[e]);
		}
		minResult = min(minResult, result);
		

		if (v[s] + v[e] > 0)
			e--;
		else if (v[s] + v[e] < 0)
			s++;
		else
			break;
	}

	cout << answer[0] << " " << answer[1];
}