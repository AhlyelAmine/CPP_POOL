#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>

class Bureaucrat
{
    private :
        const std::string name;
        int grade;
        Bureaucrat();
    public :
        ~Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& bureaucrat);
        Bureaucrat& operator=(const Bureaucrat& bureaucrat);
        int             getGrade(void) const;
        std::string     getName(void) const;
        void            incrementGrade(void);
        void            decrementGrade(void);
        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif