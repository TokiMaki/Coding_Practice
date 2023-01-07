#include <iostream>

int main(){
    int A, B;
    std::cin >> A >> B;
    if (A > 0 && B > 0)
        std::cout << "1";
    else if (A < 0 && B > 0)
        std::cout << "2";
    else if (A < 0 && B < 0)
        std::cout << "3";
    else if (A > 0 && B < 0)
        std::cout << "4";
}