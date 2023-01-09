#include <iostream>

int main(){
    int N, X;
    std::cin >> N >> X;
    int num[N];
    for(int i = 0; i < N; ++i)
        std::cin >> num[i];
    
    for(int i = 0; i < N; ++i)
        if (num[i] < X)
            std::cout << num[i] << " ";
}