#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int main()
{
    vector<int> answer;
    int n;
    vector<int> v;
    cin >> n;
    int gap = INT_MAX;
    for(int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    int s = 0, e = v.size() - 1;
    while(s < e)
    {
        if (abs(v[s] + v[e]) < gap) {
            answer.clear();
            answer.push_back(v[s]);
            answer.push_back(v[e]);
            gap = abs(v[s] + v[e]);
        }
        if (v[s] + v[e] < 0) {
            s++;
        }
        else if (v[s] + v[e] > 0) {
            e--;
        }
        else
            break;
    }

    cout << answer[0] << " " << answer[1];
}