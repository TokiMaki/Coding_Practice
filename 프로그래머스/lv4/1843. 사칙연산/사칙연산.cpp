#include <vector>
#include <string>
#include <climits>
using namespace std;

int maxdp[101][101];
int mindp[101][101];

int solution(vector<string> arr)
{
	int answer = -1;
	vector<int> num;
	vector<string> oper;
	for (string s : arr) {
		if (s == "+" || s == "-")
			oper.push_back(s);
		else
			num.push_back(stoi(s));
	}
	for (int i = 0; i < num.size(); ++i)
	{
		maxdp[i][i] = num[i];
		mindp[i][i] = num[i];
	}
	for (int i = 1; i < num.size(); ++i) {
		for (int j = 0; j < num.size() - i; ++j) {
			maxdp[j][i + j] = INT_MIN;
			mindp[j][i + j] = INT_MAX;
			for (int k = j; k < i + j; ++k) {
				if (oper[k] == "+") {
					maxdp[j][i + j] = max(maxdp[j][i + j], maxdp[j][k] + maxdp[k + 1][i + j]);
					mindp[j][i + j] = min(mindp[j][i + j], mindp[j][k] + mindp[k + 1][i + j]);
				}
				else {
					maxdp[j][i + j] = max(maxdp[j][i + j], maxdp[j][k] - mindp[k + 1][i + j]);
					mindp[j][i + j] = min(mindp[j][i + j], mindp[j][k] - maxdp[k + 1][i + j]);
				}
			}
		}
	}
	answer = maxdp[0][num.size() - 1];
	return answer;
}