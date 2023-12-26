#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm) : AForm(robotomyRequestForm.getName(), robotomyRequestForm.getGradeToSign(), robotomyRequestForm.getGradeToExecute())
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& robotomyRequestForm)
{
    (void)robotomyRequestForm;
    return (*this);
}

bool    RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (this->getGradeToExecute() < executor.getGrade())
        return (throw (AForm::GradeTooLowException()), false);
    else if (!this->getIsSigned())
    {
        std::cerr << "RobotomyRequestForm couldn't be executed by " << executor.getName() << " because form it wasn't signed!" << std::endl;
        return (false);
    }
    std::srand(std::time(NULL));
    std::cout << NOISE;
    if (random() % 2 == 0)
        std::cout << this->getName() << " has been robotomized successfully 50% of the time." << std::endl;
    else
        std::cout << this->getName() << " failed when trying to robotimize." << std::endl;
    return (true);
}
