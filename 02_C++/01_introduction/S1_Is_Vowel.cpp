#include <iostream>

bool is_vowel(char c) {

    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

}

int main(){

    char c;
    std:: cout << "please enter a letter: "<<std::endl;
    std::cin>>c;
    if (isalpha(c))
    {

        if(is_vowel(c))
            std::cout<<"the character is a vowel "<<std::endl;
        else
            std::cout<<"the character is not a vowel "<<std::endl;
    }
    else
        std::cout<<"Invalid input, please enter once more "<<std::endl;

    return 0;
}