#include "MyClass.h"

// Definition of the left shift operator
std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
    os << obj.myString;
    return os;
}

// Public member function for operator<
// bool MyClass::operator<(const MyClass& other) const {
//     return myString < other.myString;
// }

bool operator<(const MyClass& obj, const MyClass& other) {
    return obj.myString < other.myString;
}