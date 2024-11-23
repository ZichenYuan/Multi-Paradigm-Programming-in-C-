#include "func.h"

// Template function definition
template <typename T>
void printArrayElements(const T* start, const T* end) {
    for (const T* ptr = start; ptr != end; ++ptr) {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
}

// Template function definition
template <typename Iter>
void printArrayElements(Iter start, Iter end) {
    for (Iter it = start; it != end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}