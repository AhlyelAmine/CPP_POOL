#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 2);

        Form form("Form", 1, 1);
        std::cout << bureaucrat;
        std::cout << form;
        form.beSigned(bureaucrat);
        std::cout << form;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
