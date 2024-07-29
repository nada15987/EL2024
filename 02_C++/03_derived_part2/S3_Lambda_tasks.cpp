#include<iostream>
#include <algorithm>
#include <vector>

//lambda function to calculate the square of a given number
auto sqrNumber = [] (int x)
{
    return x *x ;
};

// Function to sort the array in ascending order using a lambda function
void sortArray(int arr[], int size) {
    std::sort(arr, arr + size, [](int a, int b) { return a < b; });
    std::cout << "Sorted array in ascending order: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------" << std::endl;
}

// Function to sort the array in descending order using a lambda function
void sortDescending(int arr[], int size) {
    std::sort(arr, arr + size, [](int a, int b) { return a > b; });
    std::cout << "Sorted array in descending order: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------" << std::endl;
}

int main()
{

    // Calculate the square of a number using a lambda function
    int num = 5;
    std::cout << "Square of " << num << ": " << sqrNumber(num) << std::endl;
    std::cout << "------------------------------" << std::endl;

    // Initialize an array of integers
    int arr[] = {5, 2, 9, 1, 8, 3, 4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort the array in ascending order
    sortArray(arr, size);

    // Sort the array in descending order
    sortDescending(arr, size);

    return 0 ;
}