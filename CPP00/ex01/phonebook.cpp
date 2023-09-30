#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
    contact_count = 0;
}

PhoneBook::~PhoneBook(){}

Contact PhoneBook::get_contact(int index)
{
    return (contacts[index]);
}
void PhoneBook::set_contact(Contact contact){
    contacts[contact_count % 8] = contact;
}

int PhoneBook::get_contact_count(){
    return (contact_count);
}

void PhoneBook::set_contact_count(int contact_count){
    this->contact_count = contact_count;
}

bool    get_value(std::string &value, std::string key)
{
    std::cout << key;
    std::getline(std::cin, value);
    if (std::cin.eof())
        return (false);
    return (true);
}
bool    init_contact(Contact &contact)
{
    std::string var;

    if (!get_value(var, "Enter first name: "))
        return (false);
    contact.set_first_name(var);
    if (!get_value(var, "Enter last name: "))
        return (false);
    contact.set_last_name(var);
    if (!get_value(var, "Enter nick name: "))
        return (false);
    contact.set_nickname(var);
    if (!get_value(var, "Enter phone number: "))
        return (false);
    contact.set_phone_number(var);
    if (!get_value(var, "Enter darkest secret: "))
        return (false);
    contact.set_darkest_secret(var);
    return (true);
}
bool PhoneBook::add_contact(PhoneBook &phonebook)
{
    std::string var;

    phonebook.set_contact(contact);
    phonebook.set_contact_count(phonebook.get_contact_count() + 1);
    std::cout << "Contact added." << std::endl;
    return (true);
}
