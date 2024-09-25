#include "pressure.h"
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>


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

Pressure& operator++(Pressure& pressure) {
    switch (pressure) {
        case Pressure::Low:
            pressure = Pressure::Medium;
            break;
        case Pressure::Medium:
            pressure = Pressure::High;
            break;
        case Pressure::High:
            pressure = Pressure::Low;
            break;
    }
    return pressure;
}

int main() {
    Pressure currentPressure = Pressure::Medium;
    Pressure highPressure = Pressure::High;
    Pressure lowPressure = Pressure::Low;
    Pressure pressure1 = Pressure::Low;
    Pressure pressure2 = Pressure::Medium;

    Weekday today = Weekday::Tuesday;
    Weekday tomorrow = Weekday::Wednesday;
    Weekday weekday1 = Weekday::Monday;
    Weekday weekday2 = Weekday::Friday;

    // Output Pressure comparisons
    std::cout << "Comparing Pressures:" << std::endl;
    std::cout << "Medium < High: " << (currentPressure < highPressure) << std::endl;
    std::cout << "Low < Medium: " << (lowPressure < currentPressure) << std::endl;
    std::cout << "Low < Medium: " << (pressure1 < pressure2) << std::endl;
    std::cout << "High < Low: " << (highPressure < lowPressure) << std::endl;

    // Output Weekday comparisons
    std::cout << "\nComparing Weekdays:" << std::endl;
    std::cout << "Tuesday < Wednesday: " << (today < tomorrow) << std::endl;
    std::cout << "Monday < Friday: " << (weekday1 < weekday2) << std::endl;
    std::cout << "Friday < Monday: " << (weekday2 < weekday1) << std::endl;


    std::set<Weekday> weekdaysSet1 = {Weekday::Monday, Weekday::Wednesday,Weekday::Friday};
    std::set<Weekday> weekdaysSet2 = {Weekday::Tuesday, Weekday::Thursday, Weekday::Friday};
    for (const auto& day : weekdaysSet1) {
        std::cout << day << " ";
    }
    std::cout << std::endl;

    for (const auto& day : weekdaysSet2) {
        std::cout << day << " ";
    }
    std::cout << std::endl;

    std::set<Weekday> weekdaysSet3 = {Weekday::Tuesday, Weekday::Thursday, Weekday::Friday};

    return 0;

}