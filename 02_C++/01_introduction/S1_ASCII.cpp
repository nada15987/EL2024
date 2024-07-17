#include<iostream>
#include <iomanip>

int main(){

    std::cout << "ASCII Code Table:"<<std::endl;
    for (int i=1; i<128; i++ )
    {
        std::cout << "the ASCII code is : "<< i << "  , the character is : "<< char(i) << std:: endl;

    }
    return 0;
}

