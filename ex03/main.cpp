#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    AForm* form;

    // Test de création pour chaque type de formulaire connu
    try {
        form = someRandomIntern.makeForm("robotomy request", "Robot");
        std::cout << *form << std::endl;
        delete form;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        form = someRandomIntern.makeForm("shrubbery creation", "Arboriculteur");
        std::cout << *form << std::endl;
        delete form;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        form = someRandomIntern.makeForm("presidential pardon", "President");
        std::cout << *form << std::endl;
        delete form;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test avec un nom de formulaire inconnu
    try {
        form = someRandomIntern.makeForm("unknown form", "Nobody");
    } catch (std::exception& e) {
        std::cerr << "Failed to create form: " << e.what() << std::endl;
    }

    // Test de la fonctionnalité complète avec un bureaucrate
    try {
        Bureaucrat bureaucrat("Jean-Pierre", 1); // Haut grade
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
