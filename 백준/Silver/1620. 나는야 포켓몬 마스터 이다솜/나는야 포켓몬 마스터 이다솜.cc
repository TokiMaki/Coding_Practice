#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool isNumeric(string s) {
    for (char c : s) {
        if (false == isdigit(c))
            return false;
    }
    return true;
}

int main() {
    // 출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int count = 0;
    cin >> N >> M;

    map<string, string> pokemonName;
    map<string, string> pokemonNum;
    
    for (int i = 0; i < N; ++i) {
        string tmp;
        cin >> tmp;
        pokemonName[tmp] = to_string(i + 1);
        pokemonNum[to_string(i + 1)] = tmp;
    }

    for (int i = 0; i < M; ++i) {
        string tmp;
        cin >> tmp;

        if (isNumeric(tmp))
            cout << pokemonNum[tmp] << "\n";
        else
            cout << pokemonName[tmp] << "\n";
    }
}