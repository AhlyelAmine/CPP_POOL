#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"     

class PresidentialPardonForm : public Form
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