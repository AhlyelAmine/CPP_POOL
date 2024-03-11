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

bool Date::validateDate(void)
{
    int iYear = atoi(this->sYear.c_str());
    int iMonth = atoi(this->sMonth.c_str());

    if (!check_format(4, "2024", "1900", this->sYear))
        return false;
    if (!check_format(2, "12", "01", this->sMonth))
        return false;
    if (!check_format(2, "31", "01", this->sDay))
        return false;
    if (this->sMonth == "02" && this->sDay > "29")
        return false;
    if ((iYear % 4) && this->sMonth == "2" && this->sDay == "29")
        return false;
    if (this->sMonth <= "07" && this->sMonth >= "01" && !(iMonth % 2) && this->sDay == "31")
        return false;
    if (this->sMonth <= "12" && this->sMonth >= "08"  && (iMonth % 2) && this->sDay == "31")
        return false;
    return true;
}

Date::Date(std::string year, std::string month, std::string day) : sYear(year), sMonth(month), sDay(day), date(year + "-" + month + "-" + day)
{
    if (!this->validateDate())
    {
        throw std::string("");
    }
}

Date::~Date(){}

std::ostream &operator<<(std::ostream &s, const Date&d)
{
    s << d.sYear << "-" << d.sMonth << "-" << d.sDay;
    return s;
}
