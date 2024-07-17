#include <iostream>

int get_max(int x, int y , int z){

    int max = x;
    if (y>max)
       { 
        max = y;
        return max;
       }
    else if (z>max)
    {
        max = z;
        return max;
    }
    else
        return max;
}

int main() {
    int num1;
    int num2;
    int num3;
    std::cout<<"please, enter three numbers: "<<std::endl;
    std::cin>> num1; 
    std::cin>> num2;
    std::cin>> num3;
    std::cout<<"The maximum number is: "<<get_max(num1, num2, num3)<<std::endl;
    return 0;
}