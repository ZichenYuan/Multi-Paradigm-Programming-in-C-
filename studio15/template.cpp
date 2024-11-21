#include <iostream>

static unsigned int totalSize = 0;
// template <typename T>
// void printToOstream(std::ostream& os, const T& value) {
//     // os<< "printing with printToOstream function template...";
//     os << value << " ";
// }



// template<typename T, typename... Args>
// void printWithPack(std::ostream& os, const T& first, const Args&... rest){
//     os<< first<<" ";
//     // printWithPack(os, rest...);
//     if constexpr (sizeof...(rest) > 0) {
//         printWithPack(os, rest...); // Continue with the rest
//     }
// }


// template<typename...Args>
// void printWithOnlyPack(std::ostream&os, const Args&... rest){
//     os<< "number of elements in the pack: " << sizeof...(rest) << std::endl;
//     if constexpr (sizeof...(rest) > 0) {
//         printWithOnlyPack(os, rest...);  // Call print function only if args are present
//     }
// }

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