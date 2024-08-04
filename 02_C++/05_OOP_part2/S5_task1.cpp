//check if the character is digit

#include <iostream>
#include <cctype> // for isdigit

int main() {
    char c;
    std::cout << "Enter a character: ";
    std::cin >> c;

    if (std::isdigit(c)) {
        std::cout << c << " is a digit." << std::endl;
    } else {
        std::cout << c << " is not a digit." << std::endl;
    }

    return 0;
}
