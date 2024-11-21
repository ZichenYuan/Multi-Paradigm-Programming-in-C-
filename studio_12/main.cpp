#include <iostream>
using namespace std;

typedef int i;
typedef const int ci;
typedef int * const cpi;
typedef const int * const cpci;
typedef int * pi;
typedef const int * pci;

int main(){
    // 1,2
    ci const_int_var = 0;
    i non_const_int_var = 1;

    decltype(const_int_var) auto_const_int_var = const_int_var; // Initialized with const int
    decltype(non_const_int_var) auto_non_const_int_var = non_const_int_var; // Initialized with int
    // ++auto_const_int_var;
    ++auto_non_const_int_var;

    // 3,4
    cpci const_ptr_to_const_int_1 = &const_int_var;
    cpci const_ptr_to_const_int_2 = &non_const_int_var;

    decltype(const_ptr_to_const_int_1) auto_const_ptr_to_const_int_1 = const_ptr_to_const_int_1;
    decltype(const_ptr_to_const_int_2) auto_const_ptr_to_const_int_2 = const_ptr_to_const_int_2;
    // ++auto_const_ptr_to_const_int_1;
    // ++auto_const_ptr_to_const_int_2;

    // 5,6
    pci const_ptr_to_int_1 = &const_int_var;
    pci const_ptr_to_int_2 = &non_const_int_var;
    decltype(const_ptr_to_int_1) auto_const_ptr_to_int_1 = const_ptr_to_int_1;
    decltype(const_ptr_to_int_2) auto_const_ptr_to_int_2 = const_ptr_to_int_2;
    ++auto_const_ptr_to_int_1;
    ++auto_const_ptr_to_int_2;

    // 7,8
    // int* const ptr_to_const_int_1 = &const_int_var;
    cpi ptr_to_const_int_2 = &non_const_int_var; 
    decltype(ptr_to_const_int_2) auto_ptr_to_const_int_2 = ptr_to_const_int_2; 
    // ++auto_ptr_to_const_int_2;

    // 9,10
    // int* ptr_to_int_1 = &const_int_var;
    pi ptr_to_int_2 = &non_const_int_var; 
    decltype(ptr_to_int_2) auto_ptr_to_int_2 = ptr_to_int_2; 
    ++auto_ptr_to_int_2;

    // ++const_int_var;
    ++non_const_int_var;

    // ++const_ptr_to_const_int_1;
    // ++(*const_ptr_to_const_int_1);
    // ++const_ptr_to_const_int_2;
    // ++(*const_ptr_to_const_int_2);
    ++const_ptr_to_int_1;
    // ++(*const_ptr_to_int_1);
    ++const_ptr_to_int_2;
    // ++(*const_ptr_to_int_2);
    // ++ptr_to_const_int_2;
    ++(*ptr_to_const_int_2);
    ++ptr_to_int_2;
    ++(*ptr_to_int_2);
}