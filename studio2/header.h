#include <iostream>

enum class Weekday{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

enum class Pressure{
    Low,
    Medium,
    High
};

std::ostream& operator<<(std::ostream& os, const Weekday& day);
std::ostream& operator<<(std::ostream& os, const Pressure& pressure);

Weekday operator++(Weekday& day, int);