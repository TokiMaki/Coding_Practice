#include <iostream>

int main(){
    int T, A, B;
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    
    for (int i = 0; i < T; ++i){
        std::cin >> A >> B;
        std::cout << A + B << "\n";
    }
}