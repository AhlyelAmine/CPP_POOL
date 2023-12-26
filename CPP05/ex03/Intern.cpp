#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

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

void destroy(Form *exec[], size_t i)
{
    for (size_t j = 0; j < 3; j++)
        if (i != j)
            delete (exec[j]);
}

Form*   Intern::makeForm(std::string formName, std::string target)
{
    std::string forms[3] = {PPF, RRF, SCF};
    Form        *exec[3] = {new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};
    size_t      i = 0;

    for (; i < 3; i++)
    {
        if (formName == forms[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (destroy(exec, i), exec[i]);
        }
    }
    destroy(exec, 3);
    throw (FormDoesNotExistException());
}

const char* Intern::FormDoesNotExistException::what() const throw()
{
    return ("Form does not exist");
}
