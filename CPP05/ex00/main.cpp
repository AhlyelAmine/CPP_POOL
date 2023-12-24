#include "Bureaucrat.hpp"

int main()
{
    try {

        Bureaucrat bureaucrat("Bureaucrat", 1);
        Bureaucrat bureaucrat150("Bureaucrat", 150);

        bureaucrat.incrementGrade();
        bureaucrat150.decrementGrade();

        std::cout << bureaucrat;
        std::cout << bureaucrat150;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
