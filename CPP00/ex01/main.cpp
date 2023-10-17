#include "phonebook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;
	Contact contact;
	int ret;

	while (0x5ABA)
	{
		if (!getValue(command, "Enter a command: "))
			break ;
		if (command == "EXIT")
			break;
		else if (command == "ADD"){
			if ((ret = phonebook.addContact(phonebook)) && !ret)
				break;
			else if (ret == -1)
				std::cout << "Invalid input." << std::endl;
		}
		else if (command == "SEARCH") {
			if (!phonebook.searchContact(phonebook))
				break ;
		}
		else
			std::cout << "Invalid command." << std::endl;
	}    
	return (0);
}
