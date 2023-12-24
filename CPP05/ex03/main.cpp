#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat              bureaucrat("Bureaucrat", 1);
    PresidentialPardonForm  form("Form");
    ShrubberyCreationForm   form1("Form");
    RobotomyRequestForm     form2("Form");

    std::cout << bureaucrat << std::endl;
    std::cout << form << std::endl;
    // bureaucrat.signForm("alo", 1);
    // form->beSigned(bureaucrat);
    form.beSigned(bureaucrat);
    form1.beSigned(bureaucrat);
    form2.beSigned(bureaucrat);
    form.execute(bureaucrat);
    form1.execute(bureaucrat);
    form2.execute(bureaucrat);
}
