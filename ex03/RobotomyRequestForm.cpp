#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45, target) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!isSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() >= getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "Drilling noises" << std::endl;
    srand(time(NULL));
    if (rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed on " << getTarget() << std::endl;
}
