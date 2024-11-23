#include "template.h"
#include "newFunc.h"

// Global counters for bytes
static unsigned int totalSize = 0;
static unsigned int intSize = 0;
static unsigned int floatSize = 0;

template <typename T>
void print(std::ostream& os, const T& value) {
    // os<< "printing with printToOstream function template...";
    countSize(value);
    os << value << " ";
}

template<typename T, typename... Args>
void print(std::ostream& os, const T& first, const Args&... rest){
    os<< first<<" ";
    countSize(first);
    print(os, rest...);
    // if (sizeof...(rest) > 0) {
    //     print(os, rest...); // Continue with the rest
    // }
}


template<typename...Args>
void print2(std::ostream&os, const Args&... rest){
    os<< "number of elements in the pack: " << sizeof...(rest) << std::endl;
    print(os, rest...);
}


// Function template to process an element and accumulate its size
template <typename T>
const T& countSize(const T& var) {
    totalSize += sizeof(var);  // Accumulate the size of the variable
    return var;  // Return the input variable
}

template<typename...Args>
void countSize2(std::ostream& os, const Args&... rest){
    print(os, rest...);
    os << "Total bytes in the pack: " << totalSize << std::endl;

}

// Variadic specialization for std::string
template <typename... Args>
void print(std::ostream& os, const std::string& first, const Args&... rest) {
    os << "\"" << first << "\" "; // Add quotes for std::string
    print(os, rest...);           // Recursive call
}

// Specialization for const char* const with parameter pack
template <typename... Args>
void print(std::ostream& os, const char* const value, const Args&... rest) {
    os << "[" << value << " " << reinterpret_cast<const void*>(value) << "] ";
    print(os, rest...); // Recursive call
}

// Specialization for MyClass with parameter pack
template <typename... Args>
void print(std::ostream& os, const MyClass& obj, const Args&... rest) {
    os << "{" << obj << " @" << &obj << "} ";
    print(os, rest...);
}

// Specialization for int
template <>
const int& countSize(const int& var) {
    totalSize += sizeof(var);
    intSize += sizeof(var);
    return var;
}

// Specialization for float
template <>
const float& countSize(const float& var) {
    totalSize += sizeof(var);
    floatSize += sizeof(var);
    return var;
}

// Variadic template for counting bytes and printing details
template <typename T, typename... Args>
void countSize2(std::ostream& os, const T& first, const Args&... rest) {
    countSize(first); // Apply counting function template
    if constexpr (sizeof...(rest) > 0) {
        countSize2(os, rest...); // Recursive call
    } else {
        unsigned int otherSize = totalSize - intSize - floatSize;
        os << "Total bytes: " << totalSize << "\n";
        os << "Bytes in int variables: " << intSize << "\n";
        os << "Bytes in float variables: " << floatSize << "\n";
        os << "Bytes in other types: " << otherSize << "\n";
    }
}