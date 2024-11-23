#ifndef TEMPLATEPRINT_H
#define TEMPLATEPRINT_H

#include <iostream>
#include "MyClass.h"


// Declaration of the function template
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

// Variadic specializations for std::string
template <typename... Args>
void print(std::ostream& os, const std::string& first, const Args&... rest);

// Specialization for variadic template with const char* const
template <typename... Args>
void print(std::ostream& os, const char* const value, const Args&... rest);

// Specialization for variadic template with MyClass
template <typename... Args>
void print(std::ostream& os, const MyClass& obj, const Args&... rest);

// Specializations for counting bytes in int and float
template <>
const int& countSize(const int& var);

template <>
const float& countSize(const float& var);

template <typename T, typename... Args>
void countSize2(std::ostream& os, const T& first, const Args&... rest);

#include "template.cpp"
#endif // TEMPLATEPRINT_H