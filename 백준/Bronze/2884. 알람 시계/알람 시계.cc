#include <iostream>

int main(){
    int H, M;
    std::cin >> H >> M;
    if (M - 45 < 0){
        M = 60 + (M - 45);
            H = H - 1;
        if (H < 0)
            H = 23;
    }
    else
        M -= 45;
    std::cout << H << " " << M;
}