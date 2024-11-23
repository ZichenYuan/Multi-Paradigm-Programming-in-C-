#include "MyClass.h"
#include "template.h"
#include "newFunc.h"

const int SUCCESS = 0;

namespace mynamespace {
    void printToOstream(std::ostream& os, const MyClass& value) {
        os<< "printing with printToOstream non-template function...";
        os << value;
    }
}

int main() {
    std::string myString = "myString";
    const char* const anotherString = "anotherString";
    MyClass obj1("Hello");
    int myInt = 40;
    float myFloat = 41.5;

    // Test print function with std::string specialization
    print(std::cout, myString, anotherString, myInt, myFloat, obj1);
    std::cout << std::endl;
    countSize2(std::cout, myString, anotherString, myInt, myFloat, obj1);
    std::cout << std::endl;

    return SUCCESS;
}
