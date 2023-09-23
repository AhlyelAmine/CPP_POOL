#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

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
        Contact get_contact(int index){
            return (contacts[index]);
        }
        void search_contact(PhoneBook phonebook);
        void print_contact();
        void set_contact();
        void set_contact(Contact contact){
            contacts[contact_count % 8] = contact;
        }
        int get_contact_count(){
            return (contact_count);
        }
        void set_contact_count(int contact_count){
            this->contact_count = contact_count;
        }
};

#endif