#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int recursion(const char* s, int l, int r, int* count) {
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else {
        *count = *count + 1;
        return recursion(s, l + 1, r - 1, count);
    }
}

int isPalindrome(const char* s, int* count) {
    *count = *count + 1;
    return recursion(s, 0, strlen(s) - 1, count);
}

int main() {
    int N;
    string S;
    
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int count = 0;
        cin >> S;
        cout << isPalindrome(S.c_str(), &count) << " " << count << "\n";
    }
}