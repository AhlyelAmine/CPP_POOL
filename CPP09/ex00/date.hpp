#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>
#include <ostream>

class date
{
    date();
    public:
    int year;
    int mounth;
    int day;
        date(std::string, std::string, std::string);
        ~date();
        int compare(const date&);
};

std::ostream &operator<<(std::ostream &, const date&);

#endif
