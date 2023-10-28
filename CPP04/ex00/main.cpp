#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const WrongAnimal* wrongAnimal = new WrongCat();
    WrongCat wrongCat;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << wrongAnimal->getType() << " " << std::endl;
    std::cout << wrongCat.getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    wrongCat.makeSound();
    cat->makeSound();
    dog->makeSound();
    wrongAnimal->makeSound();
    delete cat;
    delete dog;
    delete wrongAnimal;
    return 0;
}
