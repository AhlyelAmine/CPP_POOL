#pragma once
#include <iostream>

class Harl
{
    private :
        std::string debug = {"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"};
        std::string info = {"I cannot believe adding extra bacon costs more money.", "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"};
        std::string warning = {"I think I deserve to have some extra bacon for free.", "I've been coming for years whereas you started working here since last month."};
        std::string error = {"This is unacceptable! I want to speak to the manager now."};
    public :
        Harl();
        ~Harl();
        void Harl::log(std::string type);
};
