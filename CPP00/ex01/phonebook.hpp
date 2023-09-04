#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cctype>
add();
class PhoneBook
{
    private:
        std::string first_name;
        std::string last_name;
    public:
        PhoneBook();
        PhoneBook(const PhoneBook &phonebook);
        ~PhoneBook();
        PhoneBook &add=(const PhoneBook &phonebook)
        {
            this->first_name = phonebook.first_name;
            this->last_name = phonebook.last_name;
            return (*this);
        }
}