#include<iostream>
#include <algorithm> // For std::sort

//1- Function to find the maximum number of array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}


// 2- Function to search to the number in the array which number is taken from user
bool isFound(int arr1[], int arr2[], int m, int n) {
    int num=0;
    std::cout<<"please enter the number you want to search for: "<<std::endl;
    std::cin>>num;
    for (int i = 0; i < m; i++) {
        if (arr1[i] == num)
        {
            std::cout<<"the number is found in arr1 "<<std::endl;
            return true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr2[i] == num)
        {
            std::cout<<"the number is found in arr2 "<<std::endl;
            return true;
        }
    }
std::cout<<"the number is not found in any array "<<std::endl;  
 return false;  
}


// 3- Function to delete a number from the array 
void deleteNumber(int arr[], int &size) 
{   
    std::cout<<"enter the index you want to delete: "<<std::endl;
    int index;
    std::cin>>index;
    
    if (index < 0 || index >= size) {
        std::cout << "Invalid index!" << std::endl;
        return;
        }

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size --;

    std::cout << "Number deleted successfully!" << std::endl;
    std::cout << "the array after deleting the number is :" << std::endl;
    for (int i = 0 ; i < size; i++) {
        std::cout<<arr[i]<<" "; 
    }
        std::cout<<std::endl;
}

// 4- Function to merge two arrays together
void mergeArrays(int arr1[], int arr2[], int m ,int n) { 

        // Create merged array of size m + n
        int mergeLength = m+n;
        int mergedArray[mergeLength];
        int i = 0, j = 0, k = 0;

        // Copy elements of arr1 to mergedArray
         while (i < m) {
        mergedArray[k++] = arr1[i++];
        }
         // Copy elements of arr2 to mergedArray
         while (j < n) {
        mergedArray[k++] = arr2[j++];
        }
        // Print merged array
        std::cout << "Merged array is: ";
        for (i = 0; i < mergeLength ; i++) {
            std::cout << mergedArray[i] << " ";
        }
        std::cout << std::endl;

    // Sort merged array in ascending order
    std::sort(mergedArray, mergedArray + mergeLength);
    std::cout << "Merged array in ascending order: ";
    for (i = 0; i < mergeLength; i++) {
        std::cout << mergedArray[i] << " ";
    }
    std::cout << std::endl;

    // Sort merged array in descending order
    std::sort(mergedArray, mergedArray + mergeLength, std::greater<int>());
    std::cout << "Merged array in descending order: ";
    for (i = 0; i < mergeLength; i++) {
        std::cout << mergedArray[i] << " ";
    }
    std::cout << std::endl;
        
}

// 5- Function to find the even and odd numbers in the array

void findEvenAndOdd(int arr[], int size) {
    std::cout << "Even numbers: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0)
            std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Odd numbers: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0)
            std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


// 6- Function to sort the array in ascending order
    void sortArray(int arr[], int size) {
    // Sort the array using the built-in sort function in C++ STL.
    std::sort(arr, arr + size);
    std::cout << "Sorted array in ascending order: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout<<"------------------------------"<<std::endl;
}

// - Function to sort the array in descending order
    void sortDescending(int arr[], int size) {
    // Sort the array in descending order using the built-in sort function in C++ STL.
    std::sort(arr, arr + size, std::greater<int>());
    std::cout << "Sorted array in descending order: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout<<"------------------------------"<<std::endl;
}


// Main function
int main(){

    int arr1[5] = {4,5,3,1,2};
    int arr2[6] = {10,20,9,15,8,12};
    int size1 = 5;
    int size2 = 6;
    int num;
    bool exit = false;


    while (!exit)
    {

    
    //print the two arrays 
    std::cout<<"Here is the two arrays :"<<std::endl;    
    std::cout<<"arr1: ";
    for(int i=0;i<size1;i++)
        std::cout<<arr1[i]<<" ";
    std::cout<<std::endl;

    std::cout<<"arr2: ";
    for(int i=0;i<size2;i++)
        std::cout<<arr2[i]<<" ";
    std::cout<<std::endl;
    std::cout<<"------------------------------"<<std::endl;

    //menu
    std::cout<<"Choose an option:"<<std::endl;
    std::cout<<"1. Find the maximum number in each array."<<std::endl;
    std::cout<<"2. Search for a number in the array."<<std::endl;
    std::cout<<"3. Delete a number from the array."<<std::endl;
    std::cout<<"4. Merge the two arrays."<<std::endl;
    std::cout<<"5. Find the even and odd numbers in the array."<<std::endl;
    std::cout<<"6. Sort the array in ascending order."<<std::endl;
    std::cout<<"7. Sort the array in descending order."<<std::endl;
    std::cout<<"8. Exit."<<std::endl;
    int choice;
    std::cin>>choice;

   
    switch(choice){
        case 1:
            {
                // 1-get the max num in each array
                std::cout<<"the max number in the arr1 is : "<<findMax(arr1,size1)<<std::endl;
                std::cout<<"the max number in the arr2 is : "<<findMax(arr2,size2)<<std::endl;
                std::cout<<"------------------------------"<<std::endl;
                break;

            }

        case 2:
            {   
                // 2-search for a number in the array 
                isFound(arr1,arr2,size1,size2);
                std::cout<<"------------------------------"<<std::endl;
                break;
            }

        case 3:
            {
                // 3- delete a number from the array
                std::cout << "From which array do you want to delete?" << std::endl;
                std::cout << "1. arr1\n2. arr2\n";
                std::cin >> num;
                if (num == 1)
                    deleteNumber(arr1, size1);
                else if (num == 2) 
                    deleteNumber(arr2, size2);
                else 
                   std::cout << "Invalid array!" << std::endl;
                std::cout << "------------------------------" << std::endl;
                break;
            }
    
        case 4:
            {

                // 4- merge the two arrays
                mergeArrays(arr1,arr2,size1,size2);
                std::cout<<"------------------------------"<<std::endl;
                break;
            }
                
        case 5:
            {
                // 5- find the even and odd numbers in the array
                std::cout << "From which array do you want to find even and odd numbers?" << std::endl;
                std::cout << "1. arr1\n2. arr2\n";
                std::cin >> num;
                if (num == 1) {
                    findEvenAndOdd(arr1, size1);
                } else if (num == 2) {
                    findEvenAndOdd(arr2, size2);
                }

                else {
                    std::cout << "Invalid array!" << std::endl;
                }
                std::cout << "------------------------------" << std::endl;
                break;

            }
   
        case 6:
            {
                // 6- sort the array in ascending order
                std::cout << "which array do you want to sort in ascending order?" << std::endl;
                std::cout << "1. arr1\n2. arr2\n";
                std::cin >> num;
                if (num == 1) 
                    sortArray(arr1, size1);
                else if (num == 2) 
                    sortArray(arr2, size2);
                else
                    {
                        std::cout << "Invalid array!" << std::endl;
                        std::cout<<"------------------------------"<<std::endl;
                    }
                    break;


             }
    

        case 7:
            {
                // 7- sort the array in descending order
                std::cout << "which array do you want to sort in descending order?" << std::endl;
                std::cout << "1. arr1\n2. arr2\n";
                std::cin >> num;
                if (num == 1) 
                    sortDescending(arr1, size1);
                else if (num == 2) 
                    sortDescending(arr2, size2);
                else
                    {
                        std::cout << "Invalid array!" << std::endl;
                        std::cout<<"------------------------------"<<std::endl;
                    }
                break ;

            }
        case 8:
                //exit
                exit = true;
                std::cout << "Exiting..." << std::endl;
                std::cout<<"------------------------------"<<std::endl;  
                break;

        default:
                std::cout<<"Invalid choice, Please try again."<<std::endl;
                std::cout<<"------------------------------"<<std::endl;
                break;
        }
        std::cout << "------------------------------" << std::endl;
    }
    
    return 0;
}