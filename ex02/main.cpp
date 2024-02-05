#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        ShrubberyCreationForm form1("home");
        RobotomyRequestForm form2("robot");
        PresidentialPardonForm form3("someone");

        bob.signForm(form1);
        bob.executeForm(form1);

        bob.signForm(form2);
        bob.executeForm(form2);

        bob.signForm(form3);
        bob.executeForm(form3);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
