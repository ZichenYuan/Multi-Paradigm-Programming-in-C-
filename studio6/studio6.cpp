#include <iostream>
#include "header.h"

MyStruct::MyStruct() : x(0), y(0) {
    std::cout << "Default constructor called. Object address: " << this << ", x: " << x << ", y: " << y << std::endl;
}
MyStruct::MyStruct(const MyStruct& other) : x(other.x), y(other.y) {
    std::cout << "Copy constructor called. Object address: " << this 
              << ", Copied from address: " << &other << ", x: " << x << ", y: " << y << std::endl;
}

int MyStruct::getX() const {
    return x;
}

int MyStruct::getY() const {
    return y;
}

MyStruct& MyStruct::setX(int value){
    x = value;
    return *this;
}

MyStruct& MyStruct::setY(int value){
    y = value;
    return *this;
}

MyStruct MyStruct::passAndReturnByValue(MyStruct obj) {
    std::cout << " Received object address: " << &obj 
              << ", x: " << obj.getX() << ", y: " << obj.getY() << std::endl;
    return obj;
}


int main(){
    MyStruct myVariable;  
    std::cout << "Initial values:" << std::endl;
    std::cout << "x: " << myVariable.getX() << std::endl; 
    std::cout << "y: " << myVariable.getY() << std::endl;

    std::cout << "\nPassing m (before mutators) by value:\n";
    MyStruct returned1 = MyStruct::passAndReturnByValue(myVariable);

    // Using mutators on non-const object
    myVariable.setX(10).setY(20);  // Set new values using chaining of mutators
    std::cout << "\nAfter modification:" << std::endl;
    std::cout << "obj.x: " << myVariable.getX() << ", obj.y: " << myVariable.getY() << std::endl;

    std::cout << "\nPassing m (after mutators) by value:\n";
    MyStruct returned2 = MyStruct::passAndReturnByValue(myVariable);
    //5
    // MyStruct m; // default construction
    // std::cout << "m.x is" << m.getX() << "and m.y is" << m.getY() << std::endl;

    // m.setX(7).setY(3); // chained use of mutator functions
    // std::cout << "m.x is" << m.getX() << "and m.y is" << m.getY() << std::endl;

    // MyStruct n(m); // copy construction
    // std::cout << "n.x is" << n.getX() << "and n.y is" << n.getY() << std::endl;


    MyStruct copy = myVariable;
    std::cout << "copy.x: " << copy.getX() << ", copy.y: " << copy.getY() << std::endl;
    MyStruct returned3 = MyStruct::passAndReturnByValue(myVariable);
    return 0;
}