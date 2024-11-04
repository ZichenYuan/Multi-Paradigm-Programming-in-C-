#include "MyClass.h"
#include <iostream>

using namespace std;

MyClass::MyClass(const char* st): myString(st) {
    cout << "Construct" << endl;
    cout << this << endl;
    cout << st << endl;
}

MyClass::MyClass(const MyClass& mc): myString(mc.myString) {
    cout << "Copy construct" << endl;
    cout << this << endl;
    cout << &mc << endl;
    cout << myString << endl;
}

MyClass& MyClass::operator=(const MyClass& mc) {
    cout << "Assignment" << endl;
    cout << this << endl;
    cout << myString << endl;
    cout << &mc << endl;
    cout << mc.myString << endl;
    myString = mc.myString;
    return *this;
}

void MyClass::myFunc() {
    cout << "My func" << endl;
    cout << this << endl;
    cout << myString << endl;
}

MyClass::~MyClass() {
    cout << "Destruct" << endl;
    cout << this << endl;
    cout << myString << endl;
}