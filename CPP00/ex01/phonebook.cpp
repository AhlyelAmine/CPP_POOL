#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	contactCount = 0;
}

PhoneBook::~PhoneBook(){}

Contact PhoneBook::getContact(int index)
{
	return (contacts[index]);
}
int PhoneBook::getContactCount(){
	return (contactCount);
}

void PhoneBook::setContact(Contact contact){
	contacts[contactCount % 8] = contact;
}

void PhoneBook::setContactCount(int contactCount){
	this->contactCount = contactCount;
}

int    getValue(std::string &value, std::string key)
{
    std::cout << key;
	std::getline(std::cin, value);
    if (std::cin.eof())
        return (0);
	else if (value.find_first_not_of(' ') == std::string::npos || value.find_first_not_of('\t') == std::string::npos)
		return (-1);
    return (1);
}

int    initContact(Contact &contact)
{
	std::string var;
	int			ret;
	if ((ret = getValue(var, "Enter first name: ")) && ret <= 0)
		return (ret);
	contact.setFirstName(var);
	if ((ret = getValue(var, "Enter last name: ")) && ret <= 0)
		return (ret);
	contact.setLastName(var);
	if ((ret = getValue(var, "Enter nick name: ")) && ret <= 0)
		return (ret);
	contact.setNickName(var);
	if ((ret = getValue(var, "Enter phone number: ")) && ret <= 0)
		return (ret);
	contact.setPhoneNumber(var);
	if ((ret = getValue(var, "Enter darkest secret: ")) && ret <= 0)
		return (ret);
	contact.setDarkestSecret(var);
	return (1);
}

int PhoneBook::addContact(PhoneBook &phonebook)
{
	std::string var;
	Contact contact;
	int ret;
	if ((ret = initContact(contact)) && ret <= 0)
		return (ret);
	phonebook.setContact(contact);
	phonebook.setContactCount(phonebook.getContactCount() + 1);
	std::cout << "Contact added." << std::endl;
	return (1);
}

void    print_template()
{
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name"  << "|";
    std::cout << std::setw(10) << "last name"  << "|";
    std::cout << std::setw(10) << "nickname"  << std::endl;
}

bool PhoneBook::searchContact(PhoneBook phonebook)
{
	std::string s_index;
	int         index;
	int         contact_c;

	contact_c = phonebook.getContactCount() > 8 ? 8 : phonebook.getContactCount();
	print_template();
	for (int i = 0; i < contact_c; i++)
		printContactShortDesc(i);
	std::cout << "Enter an index: ";
	std::cin >> index;std::cin.ignore();
	if (std::cin.eof())
		return (false);
	if (index > 0 && index < phonebook.getContactCount() + 1)
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
	std::cout << std::setw(10) << subtenstr(contacts[index].getFirstName()) << "|";
	std::cout << std::setw(10) << subtenstr(contacts[index].getLastName()) << "|";
	std::cout << std::setw(10) << subtenstr(contacts[index].getNickName()) << std::endl;
}

void    PhoneBook::printContactDesc(int index)
{
	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "nickname: " << contacts[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
