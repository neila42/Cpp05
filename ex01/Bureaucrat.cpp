/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Probook <Probook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:05:18 by Probook           #+#    #+#             */
/*   Updated: 2024/01/26 14:32:04 by Probook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Grade too low";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) 
{
    if (_grade < 1) throw GradeTooHighException();
    if (_grade > 150) throw GradeTooLowException();
}

const std::string &Bureaucrat::getName() const 
{ 
    return _name; 
}

int Bureaucrat::getGrade() const 
{ 
    return _grade; 
}

void Bureaucrat::incrementGrade() 
{
    if (_grade <= 1) throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::decrementGrade() 
{
    if (_grade >= 150) throw GradeTooLowException();
    ++_grade;
}

void Bureaucrat::signForm(Form &form)
{
    try 
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } 
    catch (const std::exception &e) 
    {
        std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) //automatise l'impression des details
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
