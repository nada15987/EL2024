#include <iostream>


int main() {
   int num=0;
   std::cout<<"enter a number , to get its multiplication table: ";
   std::cin>>num;
   std::cout<<"Multiplication Table of "<<num<<":"<<std::endl;
   for(int i=0; i<=10; i++){
       std::cout<<num<<" * "<<i<<" = "<<num*i<<std::endl;
   }
 
    return 0;
}