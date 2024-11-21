#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
#include <string>

class MyClass {
private:
    std::string myString;

public:
    MyClass(const std::string& str) : myString(str) {}

    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj);
    // bool operator<(const MyClass& other) const;

    // This const qualifier is only appropriate for member
    // functions, where it indicates that the method does not 
    // modify the object on which it's called.
    friend bool operator<(const MyClass& obj, const MyClass& other);
};

#endif // MYCLASS_H
