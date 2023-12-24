#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade > 150)
        Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        Bureaucrat::GradeTooHighException();
    this->grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : name(bureaucrat.name)
{
    this->grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
    if (this == &bureaucrat)
        return (*this);
    this->grade = bureaucrat.grade;
    return (*this);
}

int Bureaucrat::getGrade(void) const 
{
    return (this->grade);
}

std::string Bureaucrat::getName(void) const
{
    return (this->name);
}

void Bureaucrat::incrementGrade(void)
{
    if (this->grade - 1 < 1)
        Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->grade + 1 > 150)
        Bureaucrat::GradeTooLowException();
    this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat Grade too low");
}

void    Bureaucrat::signForm(const std::string name, const bool isSigned) const
{
    if (isSigned)
        std::cout << this->name << " signed " << name << "\n";  
    else
        std::cout << this->name << " couldn’t sign " << name << " because the grade is too low\n";  
}

void Bureaucrat::executeForm(AForm const& form)
{
	if (form.execute(*this))
        std::cout << this->name << " executes " << form.getName() << std::endl;
    else
        std::cout << this->name << " cannot execute " << form.getName() << " because his grade is too low" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
    return (os);
}
