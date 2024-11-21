#include <iostream>
template <typename T>
void printToOstream(std::ostream& os, const T& value) {
    os<< "printing with printToOstream function template...";
    os << value;
}