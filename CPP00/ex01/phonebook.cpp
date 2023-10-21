#include "phonebook.hpp"

PhoneBook::PhoneBook() {
	this->contactCount = 0;
}

PhoneBook::~PhoneBook(){}

Contact PhoneBook::getContact(int index) const {
	return (this->contacts[index]);
}
int PhoneBook::getContactCount() const {
	return (this->contactCount);
}

void PhoneBook::setContact(Contact contact) {
	this->contacts[this->contactCount % 8] = contact;
}

void PhoneBook::setContactCount(int contactCount) {
	this->contactCount = contactCount;
}

bool    getValue(std::string &value, std::string key, int &ret) {
    std::cout << key;
	std::getline(std::cin, value);
    if (std::cin.eof())
        return (ret = 0, false);
	else if (value.find_first_not_of("\t \r\v\f\n") == std::string::npos)
		return (ret = -1, false);
    return (true);
}

bool    initContact(Contact &contact, int &ret) {
	std::string var;

	while (!getValue(var, "Enter first name: ", ret) && ret != 0)
		std::cout << "Invalid input." << std::endl;
	contact.setFirstName(var);
	while (ret != 0 && !getValue(var, "Enter last name: ", ret) && ret != 0)
		std::cout << "Invalid input." << std::endl;
	contact.setLastName(var);
	while (ret != 0 && !getValue(var, "Enter nick name: ", ret) && ret != 0)
		std::cout << "Invalid input." << std::endl;
	contact.setNickName(var);
	while (ret != 0 && !getValue(var, "Enter phone number: ", ret) && ret != 0)
		std::cout << "Invalid input." << std::endl;
	contact.setPhoneNumber(var);
	while (ret != 0 && !getValue(var, "Enter darkest secret: ", ret) && ret != 0)
		std::cout << "Invalid input." << std::endl;
	if (ret == 0)
		return (false);
	contact.setDarkestSecret(var);
	return (true);
}

bool PhoneBook::addContact(PhoneBook &phonebook, int &ret) {
	std::string var;
	Contact contact;
	
	if (!initContact(contact, ret))
		return (false);
	phonebook.setContact(contact);
	phonebook.setContactCount(phonebook.getContactCount() + 1);
	std::cout << "Contact added." << std::endl;
	return (true);
}

void    print_template() {
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name"  << "|";
    std::cout << std::setw(10) << "last name"  << "|";
    std::cout << std::setw(10) << "nickname"  << std::endl;
}

bool PhoneBook::searchContact(PhoneBook phonebook) const {
	int         index;
	int         contact_c;

	contact_c = phonebook.getContactCount() > 8 ? 8 : phonebook.getContactCount();
	print_template();
	for (int i = 0; i < contact_c; i++)
		printContactShortDesc(i);
	while (true)
	{
		std::cout << "Enter an index: ";
		std::cin >> index;
		if (std::cin.eof())
			return (false);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			break ;
	}
	if (index > 0 && index < phonebook.getContactCount() + 1)
		printContactDesc((index - 1) % 8);
	else
		std::cout << "Invalid index." << std::endl;
	return (true);
}

std::string subtenstr(std::string str) {
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void    PhoneBook::printContactShortDesc(int index) const {
	std::cout << std::setw(10) << index + 1 << "|";
	std::cout << std::setw(10) << subtenstr(contacts[index].getFirstName()) << "|";
	std::cout << std::setw(10) << subtenstr(contacts[index].getLastName()) << "|";
	std::cout << std::setw(10) << subtenstr(contacts[index].getNickName()) << std::endl;
}

void    PhoneBook::printContactDesc(int index) const {
	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "nickname: " << contacts[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
