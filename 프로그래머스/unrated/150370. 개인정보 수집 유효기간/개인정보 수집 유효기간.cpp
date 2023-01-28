#include <string>
#include <vector>
#include <map>
#include <string>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    class date {
    public:
        int y, m, d;
    };

    date d_today;
    vector<int> answer;
    map<char, int> termsMap;
    
    string s[3];
    int i = 0;

    for (char c : today) {
        if (c == ' ')
            break;
        else if (c != '.')
            s[i] += c;
        else if (c == '.')
            i++;
    }

    d_today.y = stoi(s[0]);
    d_today.m = stoi(s[1]);
    d_today.d = stoi(s[2]);

    // terms 거르기
    for (auto const t : terms) {
        char kind = t[0];
        int period = stoi(t.substr(2, t.length()));
        termsMap.insert(pair<char, int>(kind, period));
    }

    int num = 1;

    // privacies 거르기
    for (auto const p : privacies) {
        char kind = (*p.rbegin());
        int period = 0;

        if (termsMap.find(kind) != termsMap.end()) {
            period = termsMap.find(kind)->second;
        }

        string s[3];
        date day;
        int i = 0;

        for (char c : p) {
            if (c == ' ')
                break;
            else if (c != '.')
                s[i] += c;
            else if (c == '.')
                i++;
        }

        day.y = stoi(s[0]);
        day.m = stoi(s[1]);
        day.d = stoi(s[2]);

        day.m += period;

        while (true) {
            if (day.m > 12) {
                day.y++;
                day.m -= 12;
            }
            else
                break;
        }

        if (day.y < d_today.y
            || (day.y == d_today.y && day.m < d_today.m)
            || (day.y == d_today.y && day.m == d_today.m && day.d <= d_today.d)) {
            answer.push_back(num);
        }

        num++;
    }

    return answer;
}