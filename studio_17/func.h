#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <iostream>

// Template function declaration
template <typename T>
void printArrayElements(const T* start, const T* end);

template <typename Iter>
void printArrayElements(Iter start, Iter end);

#include "func.cpp" // Include template definitions

#endif // TEMPLATE_H