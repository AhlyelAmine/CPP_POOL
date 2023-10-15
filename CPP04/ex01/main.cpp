#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"

int main()
{
    Animal *animals[4];

    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++)
    {
        animals[i]->makeSound();
        delete animals[i];
    }
}
