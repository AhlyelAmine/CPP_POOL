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
int PhoneBook::get_contact_count(){
	return (contact_count);
}

void PhoneBook::set_contact(Contact contact){
	contacts[contact_count % 8] = contact;
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
	Contact contact;

	if (!init_contact(contact))
		return (false);
	phonebook.set_contact(contact);
	phonebook.set_contact_count(phonebook.get_contact_count() + 1);
	std::cout << "Contact added." << std::endl;
	return (true);
}

void    print_template()
{
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name"  << "|";
    std::cout << std::setw(10) << "last name"  << "|";
    std::cout << std::setw(10) << "nickname"  << std::endl;
}

bool PhoneBook::search_contact(PhoneBook phonebook)
{
	std::string s_index;
	int         index;
	int         contact_c;

	contact_c = phonebook.get_contact_count() > 8 ? 8 : phonebook.get_contact_count();
	print_template();
	for (int i = 0; i < contact_c; i++)
		printContactShortDesc(i);
	std::cout << "Enter an index: ";
	std::cin >> index;std::cin.ignore();
	if (std::cin.eof())
		return (false);
	if (index > 0 && index < phonebook.get_contact_count() + 1)
		printContactDesc((index - 1) % 8);
	else
		std::cout << "Invalid index." << std::endl;
	return (true);
}

std::string subtenstr(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void    PhoneBook::printContactShortDesc(int index)
{
	std::cout << std::setw(10) << index + 1 << "|";
	std::cout << std::setw(10) << subtenstr(contacts[index].get_first_name()) << "|";
	std::cout << std::setw(10) << subtenstr(contacts[index].get_last_name()) << "|";
	std::cout << std::setw(10) << subtenstr(contacts[index].get_nickname()) << std::endl;
}

void    PhoneBook::printContactDesc(int index)
{
	std::cout << "First name: " << contacts[index].get_first_name() << std::endl;
	std::cout << "last name: " << contacts[index].get_last_name() << std::endl;
	std::cout << "nickname: " << contacts[index].get_nickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;
}
