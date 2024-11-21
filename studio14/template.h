#ifndef TEMPLATEPRINT_H
#define TEMPLATEPRINT_H

#include <iostream>

// Declaration of the function template
template <typename T>
void printToOstream(std::ostream& os, const T& value);

#include "template.cpp"  // Include the implementation

#endif // TEMPLATEPRINT_H