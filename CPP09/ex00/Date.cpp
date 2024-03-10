#include "Date.hpp"
#include <cstdlib>

bool check_format(size_t size, std::string maxV, std::string minV, std::string target)
{
    if (target.size() != size || target > maxV || target < minV || target.find_first_not_of("0123456789") != std::string::npos)
    {
        return false;
    }
    return true;
}

bool check_existance(const Date& date)
{
    if (date.month == 2 && date.day > 29)
        return false;
    if ((date.year % 4) && date.month == 2 && date.day == 29)
        return false;
    if ((date.month <= 7 || date.month >= 1) && (date.month % 2) && date.day == 31)
        return false;
    if ((date.month <= 12 || date.month >= 8) && !(date.month % 2) && date.day == 31)
        return false;
    return true;
}

Date::Date(std::string year, std::string month, std::string day)
{
    if (!check_format(4, "2024", "1900", year))
    {
        std::string error("invalid date format " + year + "-" + month + "-" + day);
        throw error.c_str();
    }
    if (!check_format(2, "12", "01", month))
    {
        std::string error("invalid date format " + year + "-" + month + "-" + day);
        throw error.c_str();
    }
    if (!check_format(2, "31", "01", day))
    {
        std::string error("invalid date format " + year + "-" + month + "-" + day);
        throw error.c_str();
    }
    this->year = atoi(year.c_str());
    this->month = atoi(month.c_str());
    this->day = atoi(day.c_str());
    if (!check_existance(*this))
    {
        std::cout << *this << " : ";
        throw ("invalid date format");
    }
    this->date = year + "-" + month + "+" + day;
}

Date::~Date(){}

int Date::compare(const Date &date)
{
    if (this->year > date.year)
        return (1);
    else if (this->year == date.year)
    {
        if (this->month > date.month)
            return 1;
        else if (this->month == date.month)
        {
            if (this->day > date.day)
                return 1;
            else if (this->day < date.day)
                return -1;
            return 0;
        }
        return (-1);
    } 
    return (-1);
}

std::ostream &operator<<(std::ostream &s, const Date&d)
{
    s << d.year << "-" << d.month << "-" << d.day << "=> ?" << "= " << d.value;
    return s;
}
