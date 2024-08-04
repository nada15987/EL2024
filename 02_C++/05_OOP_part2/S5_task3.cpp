//check if there is any value of array is even
#include<iostream>
#include<vector>

bool IsAnyEven (const std::vector<int>& arr){

    for (int num : arr){
        if (num%2 == 0)
            return true;
    }
    return false;
        
}


int main(){

    std::vector<int> vec = {1,3,5,7,9} ; // odd array
    std::vector<int> vec2 = {2,4,5,8,9,12} ; // even and odd array

    if (IsAnyEven(vec))
        std::cout<<"there is an even element in 'vec' array "<<std::endl;
    else
        std::cout<<"there is no even element in 'vec' array"<<std::endl;

    if (IsAnyEven(vec2))
    std::cout<<"there is an even element in 'vec2' array"<<std::endl;
    else
        std::cout<<"there is no even element in 'vec2' array"<<std::endl;

    return 0;
}