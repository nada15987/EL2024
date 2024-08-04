//fill array from 10 to 10000 sequentially
#include <iostream>
#include <vector>

int main() {
    const int START = 10;
    const int END = 10000;

    // Create a vector to hold the values
    std::vector<int> vec;

    // Reserve the necessary space for the vector
    //preallocates space to avoid frequent reallocations as elements are added
    vec.reserve(END - START + 1);

    // Fill the vector with values from START to END
    for (int value = START; value <= END; ++value) {
        vec.push_back(value);
    }

    // Print the vector to verify
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
