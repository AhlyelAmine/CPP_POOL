#include "Harl.hpp"
Harl::Harl(){}
Harl::~Harl(){}

void Harl::log(std::string type)
{
    switch (type)
    {
        case (std::string)"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"):
            for (int i = 0; i < debug.size(); i++) {
                std::cout << this->debug[i] << std::endl;
            }
            break ;
        case (std::string)"I cannot believe adding extra bacon costs more money."):
            for (int i = 0; i < info.size(); i++) {
                std::cout << this->info[i] << std::endl;
            }
            break ;
        case (std::string)"You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"):
            for (int i = 0; i < info.size(); i++) {
                std::cout << this->info[i] << std::endl;
            }
            break ;
        case (std::string)"I think I deserve to have some extra bacon for free."):
            for (int i = 0; i < warning.size(); i++) {
                std::cout << this->warning[i] << std::endl;
            }
            break ;
        case (std::string)"I've been coming for years whereas you started working here since last month."):
            for (int i = 0; i < warning.size(); i++) {
                std::cout << this->warning[i] << std::endl;
            }
            break ;
        case ((std::string)"This is unacceptable! I want to speak to the manager now."):
            for (int i = 0; i < error.size(); i++) {
                std::cout << this->error[i] << std::endl;
            }
            break ;
        default :
            std::cout << "it's not an complaiment" << std::endl;
            break ;
    }    
}
