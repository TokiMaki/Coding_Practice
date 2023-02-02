#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, set<string>> report_map;
    map<string, set<string>> beReport_map;
    for (int i = 0; i < report.size(); ++i) {
        string id = "";
        string reportId = "";
        bool blank = false;
        for (char c : report[i]) {
            if (c == ' ') {
                blank = true;
                continue;
            }
            blank == false ? id += c : reportId += c;
        }
        report_map[id].insert(reportId);
        beReport_map[reportId].insert(id);
    }

    for (int i = 0; i < id_list.size(); ++i) {
        int count = 0;
        for (string s : report_map[id_list[i]]) {
            if (beReport_map[s].size() >= k)
                count++;
        }
        answer.push_back(count);
    }

    return answer;
}
