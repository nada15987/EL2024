#include <iostream>
#include <bitset>
#include <string>
#include <cmath>


//function to convert decimal to binary
std::string decimalToBinary(int decimal) 
{
    std::bitset<8> binary(decimal); // Using 8 bits for demonstration
    return binary.to_string();
}

//function to convert binary to decimal
int binaryToDecimal(const std::string& binary)
 {
    int decimal = 0;
    for (size_t i = 0; i < binary.size(); ++i) {
        if (binary[binary.size() - 1 - i] == '1') {
            decimal += std::pow(2, i);
        }
    }
    return decimal;
}

int main() {
// Decimal to Binary conversion
    int decimal;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimal;
    std::string binary = decimalToBinary(decimal);
    std::cout << "Binary representation: " << binary << std::endl;

    // Binary to Decimal conversion
    std::string binary_input;
    std::cout << "Enter a binary number: ";
    std::cin >> binary_input;
    int decimal_output = binaryToDecimal(binary_input);
    std::cout << "Decimal representation: " << decimal_output << std::endl;
    
    return 0;
}
