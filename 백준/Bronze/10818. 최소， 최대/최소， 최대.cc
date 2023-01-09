#include <iostream>
#include <algorithm>
#include <list>

int main() {
    int N;
    std::cin >> N;
    std::list<int> num;
    for (int i = 0; i < N; ++i) {
        int n;
        std::cin >> n;
        num.push_back(n);
    }
    auto a = std::minmax_element(num.begin(), num.end());
    std::cout << *a.first << " " << *a.second;
}