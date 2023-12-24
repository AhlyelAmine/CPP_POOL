#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"     

class ShrubberyCreationForm : public AForm
{
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& shrubberyCreationForm);
        bool    execute(const Bureaucrat& executor) const;
};

#endif
