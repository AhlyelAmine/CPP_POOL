#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm) : AForm(presidentialPardonForm.getName(), presidentialPardonForm.getGradeToSign(), presidentialPardonForm.getGradeToExecute())
{
    
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& presidentialPardonForm)
{
    if (this != &presidentialPardonForm)
        return (*this);
    return (*this);
}

bool    PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (this->getGradeToExecute() < executor.getGrade())
        return (throw (AForm::GradeTooLowException()), false);
    else if (!this->getIsSigned())
    {
        std::cerr << "RobotomyRequestForm couldn't be executed by " << executor.getName() << " because form it wasn't signed!" << std::endl;
        return (false);
    }
    std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox.\n";
    return (true);
}
