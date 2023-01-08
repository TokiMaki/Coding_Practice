#include <iostream>

int main(){
    int A, B, C;
    std::cin >> A >> B >> C;
    
    if (A == B && A == C)
        std::cout << 10000 + 1000 * A;
    else if (A == B || A == C)
        std::cout << 1000 + 100 * A;
    else if (B == C)
        std::cout << 1000 + 100 * B;
    else
        std::cout << 100 * std::max(std::max(A, B),C);
}