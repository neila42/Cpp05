// #include "ShrubberyCreationForm.hpp"
// #include <fstream>

// ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
//     : AForm("ShrubberyCreationForm", 145, 137, target) {}

// void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
//     if (!isSigned())
//         throw AForm::GradeTooLowException();
//     if (executor.getGrade() > getGradeToExecute())
//         throw AForm::GradeTooLowException();

//     std::ofstream ofs(getTarget() + "_shrubbery");
//     ofs << "ASCII trees" << std::endl;
//     ofs.close();
// }

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!isSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream ofs(getTarget() + "_shrubbery");
    ofs << "        ^   " << std::endl;
    ofs << "       ^^^  " << std::endl;
    ofs << "      ^^^^^ " << std::endl;
    ofs << "     ^^^^^^^" << std::endl;
    ofs << "    ^^^^^^^^^" << std::endl;
    ofs << "   ^^^^^^^^^^^" << std::endl;
    ofs << "  ^^^^^^^^^^^^^" << std::endl;
    ofs << " ^^^^^^^^^^^^^^^" << std::endl;
    ofs << "^^^^^^^^^^^^^^^^^" << std::endl;
    ofs.close();
}

