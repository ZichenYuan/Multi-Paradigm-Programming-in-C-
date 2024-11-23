#include "newFunc.h"

void print(std::ostream& os, const std::string& value) {
    os << "\"" << value << "\" ";
}

void print(std::ostream& os, const char* const value) {
    os << "[" << value << " " << reinterpret_cast<const void*>(value) << "] ";
}

void print(std::ostream& os, const MyClass& obj) {
    os << "{" << obj << " @" << &obj << "} ";
}