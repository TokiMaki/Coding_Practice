#include <iostream>

int main(){
    int n;
    std::cin >> n;
    
    for (int i = 0; i < 9; ++i)
        std::cout << n << " * " << i + 1 << " = " << n * (i + 1) << std::endl;
}