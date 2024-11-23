#include <iostream>
#include <string>
#include "MyClass.h"

// Non-template overloads
void print(std::ostream& os, const std::string& value);

void print(std::ostream& os, const char* const value); // Overload for const char* const

void print(std::ostream& os, const MyClass& obj); // Overload for MyClass
