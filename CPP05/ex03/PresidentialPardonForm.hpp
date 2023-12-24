#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"     

class PresidentialPardonForm : public AForm
{
    private:
        PresidentialPardonForm();
    public :
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& presidentialPardonForm);
        bool    execute(const Bureaucrat& executor) const;
};

#endif