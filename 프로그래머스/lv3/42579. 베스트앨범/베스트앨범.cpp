#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> map;
    unordered_map<string, int> genrestart;
    vector<pair<pair<string, int>, int>> songs;
    
    for(int i = 0; i < genres.size(); ++i) {
        map[genres[i]] += plays[i];
        songs.push_back({{genres[i], plays[i]}, i});
    }
    
    vector<pair<string, int>> stat(map.begin(), map.end());
    
    sort(songs.begin(), songs.end(), [](pair<pair<string, int>, int> a, pair<pair<string, int>, int> b){
        if (a.first.first != b.first.first)
            return a.first.first < b.first.first;
        return a.first.second > b.first.second;
    });
    
    sort(stat.begin(), stat.end(), [](pair<string, int> a, pair<string, int> b){
        return a.second > b.second;
    });
    
    for(int i = 0; i < songs.size(); ++i){
        string genre = songs[i].first.first;
        if (genrestart.find(genre) == genrestart.end())
            genrestart[genre] = i;
    }
    
    for(auto s : stat)
    {
        string genre = s.first;
        answer.push_back(songs[genrestart[genre]].second);
        if (songs[genrestart[genre] + 1].first.first == genre)
            answer.push_back(songs[genrestart[genre] + 1].second);
    }
    
    return answer;
}