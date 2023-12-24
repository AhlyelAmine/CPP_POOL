#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat()
{
    // std::cout << "destructor called for bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    // std::cout << "paramitrazed constructor called for bureaucrat" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : name(bureaucrat.name)
{
    // std::cout << "copy constructor called for bureaucrat" << std::endl;
    *this = bureaucrat;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
    // std::cout << "copy assignement operator called for bureaucrat" << std::endl;
    if (this == &bureaucrat)
        return (*this);
    this->grade = bureaucrat.grade;
    return (*this);
}

int   Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

std::string Bureaucrat::getName(void) const
{
    return (this->name);
}

void Bureaucrat::incrementGrade(void)
{
    std::cout << "incrementGrade" << std::endl;
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade(void)
{
    std::cout << "decrementGrade" << std::endl;
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
    return (os);
}
