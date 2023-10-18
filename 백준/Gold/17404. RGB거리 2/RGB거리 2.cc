#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

#define INF 1000 * 1000;

using namespace std;

int main()
{
	int N;
	vector<int> answerV;;
	int	rgb[1001][3];
	int	firstR[1001][3];
	int	firstG[1001][3];
	int	firstB[1001][3];

	cin >> N;

	for(int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 3; ++j) {
			cin >> rgb[i][j];
		}
	}
	for(int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 3; ++j) {
			firstR[i][j] = INF;
			firstG[i][j] = INF;
			firstB[i][j] = INF;
		}
	}

	firstR[0][0] = rgb[0][0];
	firstG[0][1] = rgb[0][1];
	firstB[0][2] = rgb[0][2];

	for (int i = 1; i < N; ++i)
	{
		if (i == 1)
		{
			firstR[i][1] = firstR[i - 1][0] + rgb[i][1];
			firstR[i][2] = firstR[i - 1][0] + rgb[i][2];

			firstG[i][0] = firstG[i - 1][1] + rgb[i][0];
			firstG[i][2] = firstG[i - 1][1] + rgb[i][2];

			firstB[i][0] = firstB[i - 1][2] + rgb[i][0];
			firstB[i][1] = firstB[i - 1][2] + rgb[i][1];
		}
		else if (i == N - 1)
		{
			firstR[i][1] = min(firstR[i - 1][0] + rgb[i][1], firstR[i - 1][2] + rgb[i][1]);
			firstR[i][2] = min(firstR[i - 1][0] + rgb[i][2], firstR[i - 1][1] + rgb[i][2]);

			firstG[i][0] = min(firstG[i - 1][1] + rgb[i][0], firstG[i - 1][2] + rgb[i][0]);
			firstG[i][2] = min(firstG[i - 1][0] + rgb[i][2], firstG[i - 1][1] + rgb[i][2]);

			firstB[i][0] = min(firstB[i - 1][1] + rgb[i][0], firstB[i - 1][2] + rgb[i][0]);
			firstB[i][1] = min(firstB[i - 1][0] + rgb[i][1], firstB[i - 1][2] + rgb[i][1]);
		}
		else
		{
			firstR[i][0] = min(firstR[i - 1][1] + rgb[i][0], firstR[i - 1][2] + rgb[i][0]);
			firstR[i][1] = min(firstR[i - 1][0] + rgb[i][1], firstR[i - 1][2] + rgb[i][1]);
			firstR[i][2] = min(firstR[i - 1][0] + rgb[i][2], firstR[i - 1][1] + rgb[i][2]);

			firstG[i][0] = min(firstG[i - 1][1] + rgb[i][0], firstG[i - 1][2] + rgb[i][0]);
			firstG[i][1] = min(firstG[i - 1][0] + rgb[i][1], firstG[i - 1][2] + rgb[i][1]);
			firstG[i][2] = min(firstG[i - 1][0] + rgb[i][2], firstG[i - 1][1] + rgb[i][2]);

			firstB[i][0] = min(firstB[i - 1][1] + rgb[i][0], firstB[i - 1][2] + rgb[i][0]);
			firstB[i][1] = min(firstB[i - 1][0] + rgb[i][1], firstB[i - 1][2] + rgb[i][1]);
			firstB[i][2] = min(firstB[i - 1][0] + rgb[i][2], firstB[i - 1][1] + rgb[i][2]);
		}
	}
	answerV.push_back(firstR[N - 1][1]);
	answerV.push_back(firstR[N - 1][2]);
	answerV.push_back(firstG[N - 1][0]);
	answerV.push_back(firstG[N - 1][2]);
	answerV.push_back(firstB[N - 1][0]);
	answerV.push_back(firstB[N - 1][1]);

	cout << *min_element(answerV.begin(), answerV.end());
}