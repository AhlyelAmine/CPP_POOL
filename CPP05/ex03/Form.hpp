#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    private:
        const std::string   name;
        bool                isSigned;
        const unsigned char gradeToSign;
        const unsigned char gradeToExecute;
        Form();
    public:
        virtual bool    execute(const Bureaucrat & executor) const = 0;
        virtual ~Form();
        Form(const std::string name, const int gradeToSign, const int gradeToExecute);
        Form(const Form &form);
        Form &operator=(const Form &form);
        std::string   getName(void) const;
        bool          getIsSigned(void) const;
        int           getGradeToSign(void) const;
        int           getGradeToExecute(void) const;
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        void    beSigned(const Bureaucrat &bureaucrat);

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif