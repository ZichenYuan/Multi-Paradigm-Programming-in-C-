#include "MyClass.h"
#include "move.h"
#include <memory>
#include <iostream>

using namespace std;

unique_ptr<MyClass> mainFunc(unique_ptr<MyClass> ptr) {
    ptr->myFunc();
    return ptr;
}

int main() {
    // unique_ptr<MyClass> ptr1(new MyClass("hello"));
    auto ptr1 = std::make_unique<MyClass>("hello");
    // unique_ptr<MyClass> ptr2 = std::move(ptr1);

    std::cout << "start of last question" << std::endl;

    // Using decltype and remove_reference to determine the type
    using ActualType = typename std::remove_reference<decltype(*ptr1)>::type;
    ActualType v = *ptr1; // Copy of the object pointed to by unique_ptr

    // Printing the type name using typeid and name()
    std::cout << typeid(v).name() << std::endl;

    std::cout << "end of last question" << std::endl;

    unique_ptr<MyClass> ptr2 = moveit(ptr1);
    ptr1 = mainFunc(moveit(ptr2));
    ptr1->myFunc();
    return 0;
}