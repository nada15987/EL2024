//check if all the array is even
#include<iostream>
#include<vector>

bool AreAllEven (const std::vector<int>& arr){

    for (int num : arr){
        if (num%2 != 0)
            return false;

    }
    return true;
}


int main(){

    std::vector<int> vec = {2,4,6,8,10,12} ; // even array
    std::vector<int> vec2 = {2,4,5,8,9,12} ; // even and odd array

    if (AreAllEven(vec))
        std::cout<<"all elements in 'vec' array are even"<<std::endl;
    else
        std::cout<<"not all elements in 'vec' array are even"<<std::endl;

    if (AreAllEven(vec2))
    std::cout<<"all elements in 'vec2' array are even"<<std::endl;
    else
        std::cout<<"not all elements in 'vec2' array are even"<<std::endl;

    return 0;
}