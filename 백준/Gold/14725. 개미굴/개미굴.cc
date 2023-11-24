#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>

using namespace std;

class Trie
{
public:
	map<string, Trie*> next;
	void insert(vector<string> v, int index)
	{
		if (v.size() <= index)
			return;
		auto nextFindIter = next.find(v[index]);
		if (nextFindIter == next.end())
		{
			Trie* newTrie = new Trie;
			next.emplace(v[index], newTrie);
		}
		next[v[index]]->insert(v, index + 1);
	}
	void dfs(int newLevel)
	{
		for (auto& i : next) {
			for (int j = 0; j < newLevel; j++)
				cout << "--";
			cout << i.first << '\n';
			i.second->dfs(newLevel + 1);
		}
	}
};

int main() {
	int N;
	Trie* trie = new Trie;
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		int num;
		vector<string> stringVector;
		cin >> num;
		for (int j = 0; j < num; ++j) {
			string temp;
			cin >> temp;
			stringVector.push_back(temp);
		}
		trie->insert(stringVector, 0);
	}

	trie->dfs(0);
}