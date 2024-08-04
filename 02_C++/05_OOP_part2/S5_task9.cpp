// calculate accumulate of array

#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate

int main() {
    // Example array of values
    std::vector<int> array = {10, 20, 30, 40, 50};

    // Calculate the sum of elements using std::accumulate
    int sum = std::accumulate(array.begin(), array.end(), 0);  // the initial value for the sum (0)

    // Print the sum
    std::cout << "Sum of elements: " << sum << std::endl;

    return 0;
}
