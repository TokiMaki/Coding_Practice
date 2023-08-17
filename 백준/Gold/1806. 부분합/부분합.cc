#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, S;
    cin >> N >> S;
    vector<int> sumv(N);
    int gap = INT_MAX;
    for(int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        if (i > 0)
            sumv[i] = sumv[i - 1] + temp;
        else
            sumv[i] = temp;
    }
    int size = sumv.size();
    int s = 0, e = 0;
    while(e < size && s < size)
    {
        int sum;
        if (s == 0)
            sum = sumv[e];
        else
			sum = sumv[e] - sumv[s - 1];
        if (sum >= S)
        {
            gap = min(gap, e - s + 1);
            s++;
        }
        else
        {
            e++;
        }
    }
    if (gap == INT_MAX)
        cout << 0;
    else
		cout << gap;
}