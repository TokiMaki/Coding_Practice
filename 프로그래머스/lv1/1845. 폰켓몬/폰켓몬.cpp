#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 1;
    
   
    int choice = nums.size() / 2;
    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    int numsize = nums.size();
    
    if (numsize - choice <= 0)
        answer = numsize;
    else
        answer = choice;
    
    return answer;
}