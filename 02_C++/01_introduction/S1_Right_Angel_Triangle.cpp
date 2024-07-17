#include <iostream>

int main(){

    int height=0;
    std::cout<<"please, enter the height of the right angle triangle ";
    std::cin>>height;
    for (int i=1;i<=height;i++)
    {
        for (int j=1 ; j<=i; j++)
        {
            std::cout<<"* ";
        }
        std::cout<<std::endl;
    }
    return 0;
}

