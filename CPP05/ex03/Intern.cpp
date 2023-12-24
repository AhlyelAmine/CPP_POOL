#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern& intern)
{
    *this = intern;
}

Intern& Intern::operator=(const Intern& intern)
{
    if (this == &intern)
        return (*this);
    return (*this);
}

AForm*   Intern::makeForm(std::string formName, std::string target)
{
    if (formName == PPF)
        return (new PresidentialPardonForm(target));
    else if (formName == RRF)
        return (new RobotomyRequestForm(target));
    else if (formName == SCF)
        return (new ShrubberyCreationForm(target));
    else
        throw Intern::FormDoesNotExistException();
}

const char* Intern::FormDoesNotExistException::what() const throw()
{
    return ("Form does not exist");
}
