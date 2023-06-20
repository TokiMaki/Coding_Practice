#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> path;
vector<string> answer;
vector<bool> visited;

bool allvisited(int size)
{
	for(int i = 0; i < size; ++i)
	{
        if (visited[i] == true)
            continue;
		return false;
	}
    return true;
}

void dfs(string now, vector<vector<string>> tickets)
{
    int ticketssize = tickets.size();

    path.push_back(now);

    if (allvisited(ticketssize))
    {
        if (answer.empty())
            answer = path;
        else
        {
	        for(int i = 0; i < ticketssize; ++i)
	        {
                if (answer[i] > path[i]) {
                    answer = path;
                    break;
                }
                if (answer[i] < path[i])
                    break;
	        }
        }
        return;
    }

    for(int i = 0; i < tickets.size(); ++i)
    {
	    if (visited[i] == false)
	    {
            if (tickets[i][0] == now) {
                visited[i] = true;
                dfs(tickets[i][1], tickets);
                path.pop_back();
                visited[i] = false;
            }
	    }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    for (int i = 0; i < tickets.size(); ++i)
        visited.push_back(false);
    dfs("ICN", tickets);

    return answer;
}