#include "MyClass.h"
#include <memory>

using namespace std;

unique_ptr<MyClass> mainFunc(unique_ptr<MyClass> ptr) {
    ptr->myFunc();
    return ptr;
}

int main() {
    unique_ptr<MyClass> ptr1(new MyClass("hello"));
    unique_ptr<MyClass> ptr2 = std::move(ptr1);
    ptr1 = mainFunc(std::move(ptr2));
    ptr1->myFunc();
    return 0;
}