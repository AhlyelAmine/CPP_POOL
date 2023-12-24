#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

# define PPF "presidential pardon"
# define RRF "robotomy request"
# define SCF "shrubbery creation"

class Intern
{
    public :
        Intern();
        ~Intern();
        Intern(const Intern& intern);
        Intern& operator=(const Intern& intern);
        AForm*   makeForm(std::string formName, std::string target);
        class FormDoesNotExistException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
};

#endif