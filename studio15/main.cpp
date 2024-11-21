#include "MyClass.h"
#include "template.h"

const int SUCCESS = 0;

namespace mynamespace {
    void printToOstream(std::ostream& os, const MyClass& value) {
        os<< "printing with printToOstream non-template function...";
        os << value;
    }
}

int main() {
    std::string myString = "myString";
    const char* anotherString = "anotherString";
    MyClass obj1("Hello");
    int myInt = 40;
    float myFloat = 41.5;
    // printToOstream(std::cout, myString);
    // printToOstream(std::cout, anotherString);
    // printToOstream(std::cout, obj1);
    // printToOstream(std::cout, myInt);
    // printToOstream(std::cout, myFloat);

    // print(std::cout, obj1, myString, anotherString, myInt, myFloat);
    // print2(std::cout, obj1, myString, anotherString, myInt, myFloat);
    countSize2(std::cout, obj1, myString, anotherString, myInt, myFloat);



    return SUCCESS; // Or simply return 0;
}
