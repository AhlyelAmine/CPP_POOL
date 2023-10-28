#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private :
        Brain *brain;
    public :
        Cat();
        Cat(const Cat& cat);
        Cat& operator=(const Cat& cat);
        ~Cat();
        void makeSound() const;
};
