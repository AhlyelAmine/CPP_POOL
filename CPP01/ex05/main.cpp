#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    std::string input;

    while (0x5ABA) {
        std::cout << "Enter an input : ";
        std::cin >> input;
        if (std::cin.eof() || input == "EXIT")
            return (0);
        harl.complain(input);
    }
    return (0);
}