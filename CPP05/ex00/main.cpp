#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bureaucrat("Bureaucrat", 1);
        Bureaucrat bureaucrat150("Bureaucrat", 150);

        bureaucrat150.decrementGrade();
        bureaucrat.incrementGrade();

        std::cout << bureaucrat150;
        std::cout << bureaucrat;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
