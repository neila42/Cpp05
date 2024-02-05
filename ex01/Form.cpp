/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Probook <Probook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:08:17 by Probook           #+#    #+#             */
/*   Updated: 2024/01/25 15:11:54 by Probook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw() 
{
    return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw() 
{
    return "Form grade too low";
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _signedStatus(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
    if (gradeToSign < 1 || gradeToExecute < 1) throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150) throw GradeTooLowException();
}

const std::string &Form::getName() const 
{ 
    return _name; 
}

bool Form::isSigned() const 
{ 
    return _signedStatus; 
}

int Form::getGradeToSign() const 
{ 
    return _gradeToSign; 
}

int Form::getGradeToExecute() const 
{ 
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) 
{
    if (bureaucrat.getGrade() > _gradeToSign) throw GradeTooLowException();
    _signedStatus = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) 
{
    os << form.getName() << ", form status: ";
    if (form.isSigned())
        os << "signed";
    else
        os << "not signed";
    os << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExecute();
    return os;
}

