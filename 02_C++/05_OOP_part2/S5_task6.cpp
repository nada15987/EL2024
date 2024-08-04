//trying the code

#include<iostream>

/*
This function returns a reference to a static local variable x.
The variable x is initialized to 0 only once, and it retains its value between calls to the function.
The function prints the current value of x and returns a reference to it.
*/
int &f(){
    static int x =0 ;
    std::cout <<x <<std::endl;
    return x;
}

int main() {

    f()=10;    // 0
    f()=0;     // 10
    /*
    The first call f() = 10 calls f, which prints the current value of x (initially 0), and then sets x to 10 using the reference returned by f.
    The second call f() = 0 calls f again, which now prints the current value of x (now 10), and then sets x to 0.
    */

}