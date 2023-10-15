#pragma once
#include <iostream>

class WrongAnimal
{
    protected :
        std::string type;
    public :
        WrongAnimal();
        WrongAnimal(const std::string type);
        WrongAnimal(const WrongAnimal& wrongAnimal);
        WrongAnimal& operator=(const WrongAnimal& wrongAnimal);
        void makeSound() const;
        std::string getType() const;
        ~WrongAnimal();
};
