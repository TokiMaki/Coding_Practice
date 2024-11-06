#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string S;

	cin >> S;

	set<string> substring;

	int answer = 0;


	for(int i = 0; i < S.length(); ++i)
	{
		string temp = "";
		for(int j = i; j < S.length(); ++j)
		{
			temp += S[j];
			substring.insert(temp);
		}
	}
	answer = substring.size();
	cout << answer;
}