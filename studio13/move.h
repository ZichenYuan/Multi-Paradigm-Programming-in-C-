// move.h
#ifndef MOVE_H
#define MOVE_H

#include <type_traits>  // Include for std::remove_reference
#include <typeinfo>

// Declaration and definition of the moveit function template
template <typename T>
typename std::remove_reference<T>::type&& moveit(T&& t) {
    return static_cast<typename std::remove_reference<T>::type&&>(t);
}

#endif // MOVE_H
