#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target)
    : _name(name), _signedStatus(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Form grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Form grade too low";
}

const std::string &AForm::getName() const { 
    return _name; 
}

bool AForm::isSigned() const { 
    return _signedStatus; 
}

int AForm::getGradeToSign() const { 
    return _gradeToSign; 
}

int AForm::getGradeToExecute() const { 
    return _gradeToExecute; 
}

const std::string &AForm::getTarget() const { 
    return _target; 
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signedStatus = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << form.getName() << ", form status: " << (form.isSigned() ? "signed" : "not signed") //si signed sinon not signed
       << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExecute();
    return os;
}
