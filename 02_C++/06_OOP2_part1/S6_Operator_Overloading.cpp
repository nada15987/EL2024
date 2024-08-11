#include <iostream>
#include <stdexcept>
#include <cstring>

class String{
    private:
        char *str ;
        int size;
    public:

    // Default constructor
         String() : str(nullptr), size(0) { 
        std::cout << "Default Constructor" << std::endl;
        }

        //parameterized constructor
        String (const char *str){
            size = strlen(str);
            this-> str = new char [size +1];
            strcpy(this->str, str);    
        }


    // Copy constructor (lvalue reference)
        String(const String &obj) {   // lvalue reference 
        std::cout << "Copy Constructor" << std::endl;
        size = obj.size;
        if (obj.str) {
            str = new char[size + 1];
            strcpy(str, obj.str);
        } else {
            str = nullptr;
        }
        }

    // Move constructor (rvalue reference)
        // 1- move trivial data from (t0) to (t3)
        // 2- reset (t0)

        String(String &&obj) {     // Rvalue reference
            std::cout << "Move Constructor" << std::endl;
            //for the new instance (Transfer ownership of resources)
            str = obj.str;
            size = obj.size;

            //for the new instance
            obj.str = nullptr;
            obj.size = 0;
        }


    // Destructor
     ~String (){
            delete [] str;
            str =nullptr;
             std::cout<<"Destructor"<<std::endl;
        }

    // Assignment operator (copy assignment)
        // 1- self assignment check
        // 2- delete before starting
        // 3- Allocate new memory and copy data
        // 4- Return a reference to the object

        String &operator=(const String &obj) {
        std::cout << "Assignment Operator" << std::endl;
        if (this == &obj)
            return *this; // self-assignment check

        // Delete the existing data
        delete[] str;

        // Allocate new memory and copy data
        size = obj.size;
        if (obj.str) {
            str = new char[size + 1];
            strcpy(str, obj.str);
        } else {
            str = nullptr;
        }

        return *this;
    }

    // assignment operator (move assignment)
        // 1- self assignment check
        // 2- delete before starting
        // 3- move the data
        // 4- Return a reference to the object
      
        String & operator = (String && obj){
            std::cout<<"move assignment"<<std::endl;
            if (this == &obj)
                return *this;
            if (this->str)
                delete [] this->str;
            //for new instance
            this->size = obj.size;
            this->str = obj.str;
            //for old instance
            obj.str = nullptr;
            obj.size = 0;
            return *this;
        }


    // Subscript operator (non-const version)
    char &operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return str[index];
    }

    // Subscript operator (const version)
    const char &operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return str[index];
    }

    // Concatenation operator (using +)
    String operator+(const String &obj) const {
        String temp;
        temp.size = size + obj.size;
        temp.str = new char[temp.size + 1];
        strcpy(temp.str, str);
        strcat(temp.str, obj.str);
        return temp;
    }

    // Equality operator
    bool operator==(const String &obj) const {
        if (size != obj.size) return false;
        return strcmp(str, obj.str) == 0;
    }

    // Inequality operator
    bool operator!=(const String &obj) const {
        return !(*this == obj);
    }

    // Greater-than operator
    bool operator>(const String &obj) const {
        return strcmp(str, obj.str) > 0;
    }

    // Less-than operator
    bool operator<(const String &obj) const {
        return strcmp(str, obj.str) < 0;
    }

    // Stream insertion operator (<<)
    friend std::ostream &operator<<(std::ostream &os, const String &obj) {
        os << obj.str;
        return os;
    }

    // Stream extraction operator (>>)
    friend std::istream &operator>>(std::istream &is, String &obj) {
        char buffer[1000];
        is >> buffer;
        obj = String(buffer);
        return is;
    }

    // Pre-increment operator (++str)
    String &operator++() {
        for (int i = 0; i < size; ++i) {
            str[i]++;
        }
        return *this;
    }

    // Post-increment operator (str++)
    String operator++(int) {
        String temp(*this);
        ++(*this);
        return temp;
    }

    // Negation operator (bitwise NOT)
    String operator~() const {
        String temp(*this);
        for (int i = 0; i < temp.size; ++i) {
            temp.str[i] = ~temp.str[i];
        }
        return temp;
    }

    // Logical NOT operator
    bool operator!() const {
        return size == 0 || str == nullptr;
    }

    // Addition assignment operator (+=)
    String &operator+=(const String &obj) {
        *this = *this + obj;
        return *this;
    }
};

int main() {
    // Testing the class and overloaded operators
    String str1("Hello");
    String str2("World");
    String str3 = str1 + " " + str2;
    std::cout << "Concatenated string: " << str3 << std::endl;

    // Subscript operator
    std::cout << "Character at index 1: " << str3[1] << std::endl;

    // Equality operator
    if (str1 == str2) {
        std::cout << "Strings are equal" << std::endl;
    } else {
        std::cout << "Strings are not equal" << std::endl;
    }

    // Pre-increment operator
    ++str1;
    std::cout << "Incremented str1: " << str1 << std::endl;

    // Post-increment operator
    String str4 = str1++;
    std::cout << "Post-increment str1: " << str1 << std::endl;
    std::cout << "Previous value of str1: " << str4 << std::endl;

    return 0;
}