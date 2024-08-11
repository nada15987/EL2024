#include <iostream>
#include <cstring> // For strlen, strcpy


class MyInt {
private:
    int value;
public:

    //Default constructor
    MyInt () : value(0){
        std::cout<<"Default constructor"<<std::endl;
    }

    //Parameterized constructor
    MyInt (int val) : value (val) {}

    //Copy constructor
    MyInt (const MyInt & obj) : value(obj.value) {}

    //Destructor
    ~MyInt () {}
        

    //move constructor
    MyInt (MyInt && obj)noexcept : value(obj.value) {
        obj.value = 0; // Nullify the source object's value
    }

    //Copy assignment operator
    MyInt& operator = (const MyInt & obj){
        //self assignment check
        if (this == &obj)
            return *this;
        value = obj.value;
        return *this;
    }

    //move assignment operator
    MyInt& operator = ( MyInt && obj) noexcept{
        //self assignment check
        if (this == &obj)
            return *this;

        value = obj.value;
        obj.value = 0;
        return *this;
    }

    // Arithmetic operators
    MyInt operator + (const MyInt & obj){
        return MyInt(value + obj.value);
    }

    //comparison operator   
    bool operator == (const MyInt & obj){
        return value == obj.value;
    }
    

    // print value
    void print (){
        std::cout<<value<<std::endl;
    }   
};


int main (){
    MyInt num1(10);
    MyInt num2(30);
    MyInt num3 = num1 + num2;

    num3 .print();

    if (num1 == num2)
        std::cout<<"equal"<<std::endl;
    else
        std::cout<<"not equal"<<std::endl;
    return 0;
}