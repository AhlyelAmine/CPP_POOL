#pragma once

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

class PhoneBook
{
    private :
        Contact contacts[8];
        int contact_count;
    public :
        PhoneBook();
        ~PhoneBook();
        bool add_contact(PhoneBook &phonebook);
        Contact get_contact(int index);
        void search_contact(PhoneBook phonebook);
        void print_contact();
        void set_contact();
        void set_contact(Contact contact);
        int get_contact_count();
        void set_contact_count(int contact_count);
};