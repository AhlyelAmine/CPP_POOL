#include "Harl.hpp"
Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug(void)
{

    std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI\'ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complainBook(std::string type)
{
    std::string types[] = {"DEBUG", "INFO", "WARNING",  "ERROR"};
    fnc_ptr func[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;
    for (; i < 4; i++) {
        if (type == types[i]) {
            break ;
        }
    }
    switch (i) {
        case 0:
            for (int i = 0; i < 4; i++) {
                (this->*func[i])();
            }
            break ;
        case 1:
            for (int i = 2; i < 4; i++) {
                (this->*func[i])();
            }
            break ;
        case 2:
            for (int i = 3; i < 4; i++) {
                (this->*func[i])();
            }
            break ;
        case 3:
            this->error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break ;
    }
}
