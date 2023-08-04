#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int answer = 0;
    int n;
    vector<int> v;
    int x;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cin >> x;
    sort(v.begin(), v.end());
    int s = 0, e = v.size() - 1;
    while(s < e)
    {
        if (v[s] + v[e] < x) {
            s++;
            continue;
        }
        if (v[s] + v[e] > x) {
            e--;
            continue;
        }
        if (v[s] + v[e] == x) {
            s++;
            e--;
            answer++;
        }
    }

    cout << answer;
}