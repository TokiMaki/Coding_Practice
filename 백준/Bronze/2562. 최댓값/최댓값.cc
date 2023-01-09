#include <iostream>

int main(){
    int num[9];
    int max = 0;
    int inum;
    for(int i = 0; i < 9; ++i){
        std::cin >> num[i];
        if (max < num[i]){
            max = num[i];
            inum = i;
        }
    }
    std::cout << num[inum] << std::endl;
    std::cout << inum + 1;
}