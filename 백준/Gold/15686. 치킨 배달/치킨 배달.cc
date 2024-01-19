#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int answer = INT_MAX;
int map[50][50];
bool chikenHouse[50][50];
vector<pair<int, int>> houseCoors;
vector<pair<int, int>> chikenCoors;
vector<pair<int, int>> trueChikenCoors;

int N, M;

void ChikenDistance()
{
	int resultChikenDistance = 0;
	for(pair<int, int> houseCoor : houseCoors)
	{
		int houseX = houseCoor.first;
		int houseY = houseCoor.second;

		int minChikenDistance = INT_MAX;
		for(pair<int, int> chikenCoor : trueChikenCoors)
		{
			int chikenX = chikenCoor.first;
			int chikenY = chikenCoor.second;
			int chikenDistance = abs(houseX - chikenX) + abs(houseY - chikenY);
			minChikenDistance = min(minChikenDistance, chikenDistance);
		}
		resultChikenDistance += minChikenDistance;
	}

	answer = min(answer, resultChikenDistance);
}

void SelectChikenHoust(int count, int now)
{
	if (count >= M)
	{
		ChikenDistance();
		return;
	}

	for (int i = now; i < chikenCoors.size(); ++i)
	{
		int chikenX = chikenCoors[i].first;
		int chikenY = chikenCoors[i].second;
		if (chikenHouse[chikenY][chikenX] == false)
		{
			chikenHouse[chikenY][chikenX] = true;
			trueChikenCoors.emplace_back(chikenX, chikenY);
			SelectChikenHoust(count + 1, i + 1);
			chikenHouse[chikenY][chikenX] = false;
			trueChikenCoors.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		fill_n(chikenHouse[i], N, false);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				houseCoors.emplace_back(j, i);
			if (map[i][j] == 2)
				chikenCoors.emplace_back(j, i);
		}
	}

	for (int i = 0; i < chikenCoors.size(); ++i)
	{
		int chikenX = chikenCoors[i].first;
		int chikenY = chikenCoors[i].second;
		if (chikenHouse[chikenY][chikenX] == false)
		{
			chikenHouse[chikenY][chikenX] = true;
			trueChikenCoors.emplace_back(chikenX, chikenY);
			SelectChikenHoust(1, i + 1);
			chikenHouse[chikenY][chikenX] = false;
			trueChikenCoors.pop_back();
		}
	}

	cout << answer;
}