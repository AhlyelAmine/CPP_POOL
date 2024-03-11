#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>
#include <ostream>

class Date
{
    Date();
    bool validateDate(void);
    Date(Date const &);
    Date& operator=(Date const &copy){(void)copy;return (*this);}
    public:
        std::string sYear, sMonth, sDay;
        std::string date;
        Date(std::string, std::string, std::string);
        ~Date(void);
};

std::ostream &operator<<(std::ostream &, const Date&);

#endif
