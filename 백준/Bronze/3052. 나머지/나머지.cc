#include <iostream>

int main(){
    int num[10];
    int count = 0;
    for (int i = 0; i < 10; ++i){
        std::cin >> num[i];
        num[i] %= 42;
    }
    for(int i = 0; i < 10; ++i)
        for(int j = i + 1; j < 10; ++j)
            if (num[i] == num[j]){
                count++;
                break;
            }
    std::cout << 10 - count;
}