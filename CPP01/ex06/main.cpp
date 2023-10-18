#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    std::string input;

    if (ac == 2) {
        input = av[1];
        harl.complainBook(input);
    }
    return (0);
}
