#include <iostream>
#include <cstring> // For strlen, strcpy


class MyString {
private:
    char * str;
    int size;
public:

    //Default constructor
    MyString () : str(nullptr) , size(0){
        std::cout<<"Default constructor"<<std::endl;
    }

    //Parameterized constructor
    MyString (const char * str) {
        std::cout<<"Parameterized constructor"<<std::endl;
        size= strlen(str);
        this->str = new char [size +1];
        strcpy(this->str, str);
    }

    //Copy constructor
    MyString (const MyString & obj){
        std::cout<<"copy constructor"<<std::endl;
        size = obj.size;
        if (obj.str)
        {
            this->str = new char [size +1];
            strcpy (this->str, obj.str);
        }
        else
            this->str = nullptr;
    }

    //Destructor
    ~MyString (){
        std::cout<<"Destructor"<<std::endl;
        delete [] str;
        str = nullptr;  
        }

    //move constructor
    MyString (MyString && obj){
        std::cout<<"move constructor"<<std::endl;
        size =obj.size;
        str = obj.str;
        obj.str = nullptr;
        obj.size = 0;
    }

    //Copy assignment operator
    MyString& operator = (const MyString & obj){
        //self assignment check
        if (this == &obj)
            return *this;
        delete [] str;
        if (obj.str)
        {
            size = obj.size;
            str = new char [size+1];
            strcpy (str , obj.str);
        }
        else
            str =nullptr;

        return *this;
    }


    //move assignment operator
    MyString& operator = ( MyString && obj){
        //self assignment check
        if (this == &obj)
            return *this;

        delete [] str;
        size = obj.size;
        str = obj.str;
        obj.str = nullptr;
        obj.size = 0;
        return *this;
    }


    // Concatenation operator
     MyString operator + (const MyString & obj) {
         MyString temp;
         temp.size = size + obj.size;
         temp.str = new char [temp.size +1];

         strcpy (temp.str, str);
         strcat (temp.str, obj.str);
         return temp;
     }

    // print str
    void print (){
        std::cout<<str<<std::endl;
    }   
};


int main (){
    MyString st1("hello");
    MyString st2(" world");
    MyString st3 = st1 + st2;

    st3 .print();
    return 0;
}