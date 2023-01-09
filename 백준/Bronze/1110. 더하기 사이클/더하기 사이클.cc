#include <iostream>

int main(){
    int N;
    int OldN;
    int count = 0;
    std::cin >> N;
    OldN = N;
    
    while(true){
        N = (N % 10) * 10 + ((N / 10) + (N % 10)) % 10;
        count++;
        if (N == OldN)
            break;
    }
    std::cout << count;
}