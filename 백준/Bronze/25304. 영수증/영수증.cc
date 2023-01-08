#include <iostream>

int main(){
    int X, N, a, b;
    int sum = 0;
    std::cin >> X >> N;
    for(int i = 0; i < N; ++i){
        std::cin >> a >> b;
        sum += a * b;
    }
    if (X == sum)
        std::cout << "Yes";
    else
        std::cout << "No";
}