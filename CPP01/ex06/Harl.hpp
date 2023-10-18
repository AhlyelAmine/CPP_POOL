#pragma once
#include <iostream>

class Harl
{
    private :
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public :
        Harl();
        ~Harl();
        void complainBook(std::string level);
};

typedef void (Harl::*fnc_ptr) ( void );
