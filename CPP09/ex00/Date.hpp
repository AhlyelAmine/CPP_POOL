#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>
#include <ostream>

class Date
{
    Date();
    public:
    int year;
    int month;
    int day;
    std::string date;
    double value;
    Date(std::string, std::string, std::string);
    ~Date();
    int compare(const Date&);
};

std::ostream &operator<<(std::ostream &, const Date&);

#endif
