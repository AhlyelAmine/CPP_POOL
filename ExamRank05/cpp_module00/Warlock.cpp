#include "Warlock.hpp"

const std::string Warlock::getName() const
{
    return (this->name);
}

const std::string Warlock::getTitle() const
{
    return (this->title);
}

void Warlock::setTitle(const std::string& title)
{
    this->title = title;
}

Warlock::Warlock(const std::string& name, const std::string& title) : name(name), title(title)
{
    std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!\n";


}
void Warlock::introduce() const
{
    std::cout << this->name << ": I am" << this->name << ", " << this->title << "!\n";
}
