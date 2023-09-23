#include "phonebook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;
    while (1)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            break;
        if (command == "EXIT")
            break;
        else if (command == "ADD"){
            if (!phonebook.add_contact(phonebook))
                break;
        }
        else if (command == "SEARCH")
            phonebook.search_contact(phonebook);
        else
            std::cout << "Invalid command." << std::endl;
    }    
    return (0);
}
