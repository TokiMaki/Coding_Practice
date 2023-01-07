#include <iostream>

int main(){
    int A, B;
    std::cin >> A >> B;
    int Btemp = B;
    while (Btemp > 0){
        int remain = Btemp % 10;
        std::cout << A * remain << std::endl;
        Btemp /= 10;
    }
    std :: cout << A * B << std::endl;
}