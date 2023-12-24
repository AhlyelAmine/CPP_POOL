#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# define NOISE "saaba saaba saaba saaba saaba saaba saaba saaba saaba saaba saaba saaba\nsaaba saaba saaba saaba saaba saaba saaba saaba saaba saaba saaba saaba\nsaaba saaba saaba saaba saaba saaba saaba saaba saaba saaba saaba saaba\nsaaba saaba saaba saaba saaba saaba saaba saaba saaba saaba saaba sa\n"
#include "AForm.hpp"     

class RobotomyRequestForm : public AForm
{
        RobotomyRequestForm();
    public :
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& robotomyRequestForm);
        bool    execute(const Bureaucrat& executor) const;
};

#endif
