#include <string>

class MyClass {
    private:
    std::string myString;

    public:
    MyClass() = default;
    MyClass(char* st);
    MyClass(const MyClass& mc);

    MyClass& operator=(const MyClass& mc);

    virtual void myFunc();

    virtual ~MyClass();
};