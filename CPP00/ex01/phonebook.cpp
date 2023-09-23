#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
    contact_count = 0;
}

PhoneBook::~PhoneBook(){}

bool PhoneBook::add_contact(PhoneBook &phonebook)
{
    Contact contact;
    std::string var;

    std::cout << "Enter first name: ";
    std::getline(std::cin, var);
    contact.set_first_name(var);
    if (std::cin.eof())
        return (false);

    std::cout << "Enter last name: ";
    std::getline(std::cin, var);
    contact.set_last_name(var);
    if (std::cin.eof())
        return (false);

    std::cout << "Enter nick name: ";
    std::getline(std::cin, var);
    contact.set_nickname(var);
    if (std::cin.eof())
        return (false);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, var);
    contact.set_phone_number(var);
    if (std::cin.eof())
        return (false);

    std::cout << "Enter darkest secret: ";
    std::setw(10);
    std::getline(std::cin, var);
    contact.set_darkest_secret(var);
    if (std::cin.eof())
        return (false);

    phonebook.set_contact(contact);
    phonebook.set_contact_count(phonebook.get_contact_count() + 1);
    std::cout << "Contact added." << std::endl;
    return (true);
}

std::string subtenstr(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void PhoneBook::search_contact(PhoneBook phonebook)
{
    std::string s_index;
    int         index;

    std::cout <<  std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name"  << "|";
    std::cout << std::setw(10) << "last name"  << "|";
    std::cout << std::setw(10) << "nickname"  << std::endl;
    for (int i = 0; i < (phonebook.get_contact_count() > 8 ? 8 : phonebook.get_contact_count()); i++)
    {
        Contact contact = phonebook.get_contact(i);
        std::string index = std::to_string(i + 1);
        std::cout << std::setw(10) << subtenstr(index) << "|";
        std::cout << std::setw(10) << subtenstr(contact.get_first_name()) << "|";
        std::cout << std::setw(10) << subtenstr(contact.get_last_name()) << "|";
        std::cout << std::setw(10) << subtenstr(contact.get_nickname()) << std::endl;
    }
    std::cout << "Enter an index: ";
    std::getline(std::cin, s_index);
    if (std::cin.eof())
        return ;
    index = atoi(s_index.c_str());
    if (index && index < phonebook.get_contact_count() + 1)
    {
        std::cout << "First name: " << phonebook.get_contact((index - 1) % 8).get_first_name() << std::endl;
        std::cout << "last name: " << phonebook.get_contact((index - 1) % 8).get_last_name() << std::endl;
        std::cout << "nickname: " << phonebook.get_contact((index - 1) % 8).get_nickname() << std::endl;
        std::cout << "Phone Number: " << phonebook.get_contact((index - 1) % 8).get_phone_number() << std::endl;
        std::cout << "Darkest Secret: " << phonebook.get_contact((index - 1) % 8).get_darkest_secret() << std::endl;
    }
    else
        std::cout << "Invalid index." << std::endl;
}
