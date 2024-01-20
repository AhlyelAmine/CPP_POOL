#include "AForm.hpp"

AForm::~AForm() {}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : 
name(name), gradeToSign(gradeToSign),  gradeToExecute(gradeToExecute)
{
    if (gradeToExecute < 1 || gradeToSign < 1){
            throw (AForm::GradeTooHighException());
    }
    else if (gradeToExecute > 150 || gradeToSign > 150)
    {
        throw (AForm::GradeTooLowException());
    }
    this->isSigned = false;   
}

AForm::AForm(const AForm &form) : name(form.name),  gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute)
{
    this->isSigned = form.isSigned;
}

AForm&  AForm::operator=(const AForm& form)
{
    this->isSigned = form.isSigned;
    return (*this);
}

std::string AForm::getName(void) const
{
    return (this->name);
}

bool    AForm::getIsSigned(void) const
{
    return (this->isSigned);
}

int AForm::getGradeToSign(void) const
{
    return (this->gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
    return (this->gradeToExecute);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("AForm Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("AForm Grade too low");
}

void    AForm::beSigned(const Bureaucrat &bureaucrat)
{
    bool    check = bureaucrat.getGrade() <= this->gradeToSign;
    if (check)
        this->isSigned = true;
    bureaucrat.signForm(this->name, this->isSigned);
    if (!check)
        throw (AForm::GradeTooLowException());
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << form.getName() << "\nsigned : " << (form.getIsSigned() ? "true" : "false") << "\ngrade to sign : " << form.getGradeToSign() << "\ngrade to execute : " << form.getGradeToExecute() << "\n";
    return (os);
}
