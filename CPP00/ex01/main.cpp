#include "phonebook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;
	Contact contact;

	while (0x5ABA)
	{
		int ret = 1;
		if (!getValue(command, "Enter a command: ", ret) && !ret)
			break ;
		if (command == "EXIT")
			break;
		else if (command == "ADD"){
			if (!phonebook.addContact(phonebook, ret)) {
				if (!ret)
					break;
				else
					std::cout << "Invalid input." << std::endl;
			}
		}
		else if (command == "SEARCH") {
			if (!phonebook.searchContact(phonebook))
				break ;
			else
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
		else
			std::cout << "Invalid command." << std::endl;
	}    
	return (0);
}
