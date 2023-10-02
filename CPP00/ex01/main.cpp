#include "phonebook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;
	Contact contact;

	while (0x5ABA)
	{
		if (!get_value(command, "Enter a command: "))
			break ;
		if (command == "EXIT")
			break;
		else if (command == "ADD"){
			if (!phonebook.add_contact(phonebook))
				break;
		}
		else if (command == "SEARCH") {
			if (!phonebook.search_contact(phonebook))
				break ;
		}
		else
			std::cout << "Invalid command." << std::endl;
	}    
	return (0);
}
