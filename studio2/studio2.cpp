#include "header.h"
#include <iostream>


std::ostream& operator<<(std::ostream& os, const Weekday& day){
    switch(day){
        case Weekday::Monday:
            os << "Mon";
            break;
        case Weekday::Tuesday:
            os << "Tue";
            break;
        case Weekday::Wednesday:
            os << "Wed";
            break;
        case Weekday::Thursday:
            os << "Thu";
            break;
        case Weekday::Friday:
            os << "Fri";
            break;
        case Weekday::Saturday:
            os << "Sat";
            break;
        case Weekday::Sunday:
            os << "Sun";
            break;
    }
    os << " ";
    return os;
}

Weekday operator++(Weekday& day, int){
    Weekday old = day;
    switch(day){
        case Weekday::Sunday: day = Weekday::Monday; break;
        case Weekday::Monday: day = Weekday::Tuesday; break;
        case Weekday::Tuesday: day = Weekday::Wednesday; break;
        case Weekday::Wednesday: day = Weekday::Thursday; break;
        case Weekday::Thursday: day = Weekday::Friday; break;
        case Weekday::Friday: day = Weekday::Saturday; break;
        case Weekday::Saturday: day = Weekday::Sunday; break;
    }
    return old;
}

std::ostream& operator<<(std::ostream& os, const Pressure& pressure) {
    switch (pressure) {
        case Pressure::Low:
            os << "Low";
            break;
        case Pressure::Medium:
            os << "Medium";
            break;
        case Pressure::High:
            os << "High";
            break;
    }
    os << " "; 
    return os;
}

int main() {
    Pressure currentPressure = Pressure::Medium;
    std::cout << currentPressure << std::endl;
    return 0;

    // Weekday today = Weekday::Monday;
    // std::cout << today << std::endl;
    // return 0;

    // Weekday today = Weekday::Sunday;

    // // Use a do-while loop to cycle through all possible values of Weekday
    // do {
    //     std::cout << today;
    //     today++;
    // } while (today != Weekday::Sunday); 

    // std::cout << std::endl;
}