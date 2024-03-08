#include "date.hpp"
#include <cstdlib>

bool check_format(size_t size, std::string maxV, std::string minV, std::string target)
{
    if (target.size() != size || target > maxV || target < minV || target.find_first_not_of("0123456789") != std::string::npos)
    {
        return false;
    }
    return true;
}

bool check_existance(const date& date)
{
    if (date.mounth == 2 && date.day > 29)
        return false;
    if ((date.year % 4) && date.mounth == 2 && date.day == 29)
        return false;
    if ((date.mounth <= 7 || date.mounth >= 1) && (date.mounth % 2) && date.day == 31)
        return false;
    if ((date.mounth <= 12 || date.mounth >= 8) && !(date.mounth % 2) && date.day == 31)
        return false;
    return true;
}

date::date(std::string year, std::string mounth, std::string day)
{
    if (!check_format(4, "2022", "2009", year))
    {
        std::string error("invalid date format " + year + "-" + mounth + "-" + day);
        throw error;
    }
    if (!check_format(2, "12", "01", mounth))
    {
        std::string error("invalid date format " + year + "-" + mounth + "-" + day);
        throw error;
    }
    if (!check_format(2, "31", "01", day))
    {
        std::string error("invalid date format " + year + "-" + mounth + "-" + day);
        throw error;
    }
    this->year = atoi(year.c_str());
    this->mounth = atoi(mounth.c_str());
    this->day = atoi(day.c_str());
    if (!check_existance(*this))
    {
        std::cout << *this << " : ";
        throw "invalid date format";
    }
}

date::~date(){}

int date::compare(const date &date)
{
    if (this->year > date.year)
        return (1);
    else if (this->year == date.year)
    {
        if (this->mounth > date.mounth)
            return 1;
        else if (this->mounth == date.mounth)
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

std::ostream &operator<<(std::ostream &s, const date&d)
{
    s << d.year << "-" << d.mounth << "-" << d.day;
    return s;
}
