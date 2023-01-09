#include <iostream>

int main(){
    int N, v;
    std::cin >> N;
    int num[N];
    int count = 0;
    
    for(int i = 0; i < N; ++i)
        std::cin >> num[i];
    
    std::cin >> v;
    
    for(int i = 0; i < N; ++i)
        if (num[i] == v)
            count++;
    
    std::cout << count;
}