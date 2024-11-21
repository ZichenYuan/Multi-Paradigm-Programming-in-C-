#ifndef TEMPLATEPRINT_H
#define TEMPLATEPRINT_H

#include <iostream>

// Declaration of the function template
// template <typename T>
// void printToOstream(std::ostream& os, const T& value);

// template <typename T, typename ...Args>
// void printWithPack(std::ostream& os, const T& first, const Args&... rest);

// template<typename ...Args>
// void printWithOnlyPack(std::ostream&os, const Args&... rest);
template <typename T>
void print(std::ostream& os, const T& value);

template <typename T, typename ...Args>
void print(std::ostream& os, const T& first, const Args&... rest);

template<typename ...Args>
void print2(std::ostream&os, const Args&... rest);

template <typename T>
const T& countSize(const T& var);

template<typename...Args>
void countSize2(std::ostream& os, const Args&... rest);

#include "template.cpp"  // Include the implementation

#endif // TEMPLATEPRINT_H