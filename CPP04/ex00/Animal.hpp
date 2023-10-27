#pragma once
#include <iostream>

class Animal
{
    protected :
        std::string type;
    public :
        Animal();
        Animal(const std::string type);
        Animal(const Animal& animal);
        Animal& operator=(const Animal& animal);
        virtual void makeSound() const;
        std::string getType() const;
        virtual ~Animal();
};
