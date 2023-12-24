#ifndef AFORM_HPP
# define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool                isSigned;
        const int           gradeToSign;
        const int           gradeToExecute;
        AForm();
    public:
        virtual bool    execute(const Bureaucrat & executor) const = 0;
        ~AForm();
        AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm &form);
        AForm &operator=(const AForm &form);
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

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif