//write string class which has Members { length - string}

#include <iostream>
#include <cstring>   //for strlen and strcpy

class String{
    private:
        char *str;  //Pointer to a dynamically allocated array of characters to store the string.
        std::size_t length;   //unsigned int

    public:

        // Default constructor
        String() : str(nullptr), length(0) {}

        //constructor
        String(const char* s);

        //copy constructor
        String(const String& other);

        // Assignment operator
        String& operator=(const String& other) {
        if (this == &other) {
            return *this;
        }
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
        return *this;
        }

        // Destructor   
        ~String() ;

         // Method to set the string value
        void setString(const char* s) ;

        // Method to get the string value
        const char* getString() const ;

        // Method to get the length of the string
        std::size_t getLength() const ;

        // Method to print the string
        void print() const ;

};

// constructor
String::String(const char* s) {
    length = std::strlen(s);
    str = new char[length + 1];
    std::strcpy(str, s);
}

// copy constructor
String::String(const String& other) {
    length = other.length;
    str = new char[length + 1];
    std::strcpy(str, other.str);
}

// Destructor
String:: ~String(){
    delete[] str;
}


// Method to set the string value
void String::setString(const char* s) {
    delete[] str;
    length = std::strlen(s);
    str = new char[length + 1];
    std::strcpy(str, s);
}

// Method to get the string value
const char* String::getString() const {
    return str;
}

// Method to get the length of the string
std::size_t String::getLength() const {
    return length;
}

// Method to print the string
void String::print() const {
    if (str ) {
        std::cout << "string: "<<str << " & length: "<<length <<std::endl;
    }
    else
        std::cout << "String is empty." << std::endl;
        return;
}

int main() {
    String s1("Hello, world!");
    s1.print();

    String s2;
    s2.setString("C++ Programming");
    s2.print();

    String s3 = s2; // Using copy constructor
    s3.print();

    s1 = s3; // Using assignment operator
    s1.print();

    return 0;
}
