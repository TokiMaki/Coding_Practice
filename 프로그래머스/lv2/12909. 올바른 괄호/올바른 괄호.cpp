#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> st;
    for(char t : s) {
        if (t == '(') 
            st.push(1);
        else if (!st.empty())
            st.pop();
        else {
            answer = false;
            break;
        }
    }
    if (!st.empty())
        answer = false;
    return answer;
}