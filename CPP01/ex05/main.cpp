#include "Harl.hpp"

int main()
{
    Harl harl;
    std::string input;

    while (0x5ABA) {
        std::cout << "Enter an input : ";
        getline(std::cin, input);
        if (std::cin.eof() || input == "EXIT")
            return (0);
        harl.complain(input);
    }
    return (0);
}
