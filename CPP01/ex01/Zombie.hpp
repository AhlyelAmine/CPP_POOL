#pragma once
#include <iostream>

class Zombie {
    private : 
        std::string name;
    public :
        Zombie(std::string name);
        void    setName(std::string name);
        Zombie();
        ~Zombie();
        void announce(void);
};

Zombie* zombieHorde(int N, std::string name);
