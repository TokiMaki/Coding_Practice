#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    int answer = 0;

    vector<bool> prime(N + 1);
    vector<int> v;


    fill_n(prime.begin(), N + 1, true);
    for(int i = 2; i * i <= N; ++i)
    {
        if (prime[i] == true)
        {
            for(int j = i * i; j <= N; j += i)
            {
                prime[j] = false;
            }
        }
    }

    for(int i = 2; i <= N; ++i)
    {
        if (prime[i] == true)
        {
            v.push_back(i);
        }
    }

    for(int i = 1; i < v.size(); ++i)
    {
    	v[i] = v[i] + v[i - 1];
    }

    int s = 0; int e = 0;
    while(s < v.size() && e < v.size())
    {
        int sum = v[e];
        if (s > 0)
            sum -= v[s - 1];
        if (sum < N)
        {
            e++;
        }
        else if (sum == N)
        {
            answer++;
            e++;
        }
        else if (sum > N)
        {
            s++;
        }
    }

    cout << answer;
}