#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

const Intern::FormCreationEntry Intern::formCreationTable[] = {
    {"presidential pardon", &Intern::createPresidentialPardonForm},
    {"robotomy request", &Intern::createRobotomyRequestForm},
    {"shrubbery creation", &Intern::createShrubberyCreationForm},
    {"" , nullptr}
};

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    for (const FormCreationEntry* entry = formCreationTable; entry->createFunc != nullptr; ++entry) {
        if (formName == entry->name) {
            std::cout << "Intern creates " << formName << std::endl;
            return entry->createFunc(target);
        }
    }
    std::cout << "Error: Form \"" << formName << "\" does not exist" << std::endl;
    return nullptr; //mieux que NULL en c++
}
