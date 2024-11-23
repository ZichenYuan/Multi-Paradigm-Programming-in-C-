#include <iostream>
#include "func.h"
#include <deque>
#include <vector>
#include <list>

const int SUCCESS = 0;

int main() {
    // Declare and initialize a C-style array of int
    int intArray[] = {1, 2, 3, 4};

    // // Output sizeof the array and sizeof the array's type
    // std::cout << "Size of the array: " << sizeof(intArray) << " bytes\n";
    // std::cout << "Size of the array's element type: " << sizeof(intArray[0]) << " bytes\n";

    // // Calculate the pointer just past the end of the array
    // int* start = intArray;
    // int* end = intArray + (sizeof(intArray) / sizeof(intArray[0]));

    // // Iterate using a pointer and print the values
    // for (int* ptr = start; ptr != end; ++ptr) {
    //     std::cout << *ptr << " ";
    // }
    // std::cout << std::endl;

    // // Call the template function with array bounds
    // printArrayElements(intArray, intArray + (sizeof(intArray) / sizeof(intArray[0])));

    // std::cout << std::endl;

    // Declare containers
    std::deque<int> intDeque;
    std::vector<int> intVector;
    std::list<int> intList;

    // Populate containers using a pointer to iterate through the array
    for (const int* ptr = intArray; ptr != intArray + (sizeof(intArray) / sizeof(intArray[0])); ++ptr) {
        intDeque.emplace_back(*ptr);
        intVector.emplace_back(*ptr);
        intList.emplace_back(*ptr);
    }

    // // Print array contents
    // std::cout << "Array: ";
    // printArrayElements(intArray, intArray + (sizeof(intArray) / sizeof(intArray[0])));

    // // Print deque contents
    // std::cout << "Deque: ";
    // printArrayElements(intDeque.begin(), intDeque.end());

    // // Print vector contents
    // std::cout << "Vector: ";
    // printArrayElements(intVector.begin(), intVector.end());

    // // Print list contents
    // std::cout << "List: ";
    // printArrayElements(intList.begin(), intList.end());

    // Declare an iterator for the vector and initialize it to point one position past the beginning
    std::vector<int>::iterator iter = intVector.begin() + 1;

    // Call the function template with the vector's begin and the iterator
    std::cout << "First segment: ";
    printArrayElements(intVector.begin(), iter);

    // Call the function template with the iterator and the vector's end
    std::cout << "Second segment: ";
    printArrayElements(iter, intVector.end());

    // Reposition the iterator to point to the middle of the vector's range
    iter = intVector.begin() + (intVector.end() - intVector.begin()) / 2;

    // Call the function template with the vector's begin and the repositioned iterator
    std::cout << "First half: ";
    printArrayElements(intVector.begin(), iter);

    // Call the function template with the repositioned iterator and the vector's end
    std::cout << "Second half: ";
    printArrayElements(iter, intVector.end());

    // Access and print the 0th element
    std::cout << "Array 0th element: " << intArray[0] << std::endl;
    std::cout << "Deque 0th element: " << intDeque[0] << std::endl;
    std::cout << "Vector 0th element: " << intVector[0] << std::endl;
    // std::cout << "List 0th element: " << intList[0] << std::endl;

    return SUCCESS;
}
