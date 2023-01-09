#include <iostream>

int main(){
    bool student[30];
    std::fill_n(student, 30, false);
    int num[28];
    for(int i = 0; i < 28; ++i){
        std::cin >> num[i];
        student[num[i] - 1] = true;
    }
    for(int i = 0; i < 30; ++i)
        if (student[i] == false)
            std::cout << i + 1 << std::endl;
}