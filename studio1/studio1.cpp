#include "header.h"
int main() {
    // Construct two objects of the struct with different integer values
    MyStruct obj1{1};
    MyStruct obj2{2};

    // Print out their member variables with a space in between
    std::cout << obj1.value << " " << obj2.value << std::endl;

    std::swap(obj1,obj2);
  
    std::cout << "after swap: " << obj1.value << " " << obj2.value << std::endl;
    // Return a descriptively named symbol to indicate success
    const int SUCCESS_EXIT_CODE = 0;
    return SUCCESS_EXIT_CODE;
}