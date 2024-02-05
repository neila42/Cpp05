#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Grade too low";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) 
{
    if (grade < 1) throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
}

const std::string &Bureaucrat::getName() const 
{ 
    return name; 
}

int Bureaucrat::getGrade() const 
{ 
    return grade; 
}

void Bureaucrat::incrementGrade() 
{
    if (grade <= 1) throw GradeTooHighException(); //si en incrementant ca devient une err
    --grade;
}

void Bureaucrat::decrementGrade() 
{
    if (grade >= 150) throw GradeTooLowException();
    ++grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
