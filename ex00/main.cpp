#include "Bureaucrat.hpp"

int main() 
{
    try
    {
        Bureaucrat b("Monsieur X", 2);
        std::cout << b << std::endl;

        b.incrementGrade();
        std::cout << b << std::endl;

        b.decrementGrade();
        b.decrementGrade();
        std::cout << b << std::endl;
    } 
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
