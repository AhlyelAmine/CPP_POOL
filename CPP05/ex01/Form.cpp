#include "Form.hpp"

Form::~Form() {}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : 
name(name), gradeToSign(gradeToSign),  gradeToExecute(gradeToExecute)
{
    if (gradeToExecute < 1 || gradeToSign < 1){
            throw (Form::GradeTooHighException());
    }
    else if (gradeToExecute > 150 || gradeToSign > 150)
    {
        throw (Form::GradeTooLowException());
    }
    this->isSigned = false;
}

Form::Form(const Form& form) : name(form.name),  gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute)
{
    this->isSigned = form.isSigned;
}

Form& Form::operator=(const Form& form)
{
    if (this == &form)
        return (*this);
    this->isSigned = form.isSigned;
    return (*this);
}

std::string   Form::getName(void) const
{
    return (this->name);
}

bool    Form::getIsSigned(void) const
{
    return (this->isSigned);
}

int Form::getGradeToSign(void) const
{
    return (this->gradeToSign);
}

int Form::getGradeToExecute(void) const
{
    return (this->gradeToExecute);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form Grade too low");
}

void    Form::beSigned(const Bureaucrat &bureaucrat)
{
    bool    check = bureaucrat.getGrade() <= this->gradeToSign;
    if (check)
        this->isSigned = true;
    bureaucrat.signForm(this->name, this->isSigned);
    if (!check)
        throw (Form::GradeTooLowException());
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << form.getName() << " :\nsigned : " << (form.getIsSigned() ? "yes" : "no") << "\ngrade to sign : " << form.getGradeToSign() << "\ngrade to execute : " << form.getGradeToExecute() << "\n";
    return (os);
}
