#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5, target) {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!isSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() >= getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
