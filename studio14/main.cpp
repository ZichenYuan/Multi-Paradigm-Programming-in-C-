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
    MyClass obj1("Hello");
    MyClass obj2("World");

    // std::cout << obj1 << " " << obj2 << std::endl;


    // printToOstream(std::cout, obj1);
    // std::cout << " ";
    // printToOstream(std::cout, obj2);
    // std::cout << std::endl;

    std::cout << "Outputting obj1: ";
    mynamespace::printToOstream(std::cout, obj1);  // Use the non-template function
    std::cout << std::endl;

    std::cout << "Outputting obj2: ";
    printToOstream(std::cout, obj2);  // Use the template function
    std::cout << std::endl;



    std::cout << "Comparing obj1 and obj2: ";
    if (obj1 < obj2) {
        std::cout << "obj1 (";
        printToOstream(std::cout,obj1);
        std::cout << ") is less than obj2 (";
        printToOstream(std::cout, obj2); 
        std::cout<< ")" << std::endl;
    } else {
        std::cout << "obj1 (";
        mynamespace::printToOstream(std::cout,obj1);
        std::cout << ") is not less than obj2 (";
        mynamespace::printToOstream(std::cout, obj2); 
        std::cout<< ")" << std::endl;
    }


    return SUCCESS; // Or simply return 0;
}
