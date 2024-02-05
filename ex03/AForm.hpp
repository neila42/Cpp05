#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
    class GradeTooHighException : public std::exception {
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char *what() const throw();
    };

    AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target);
    virtual ~AForm();
    const std::string &getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    const std::string &getTarget() const;
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;

private:
    const std::string _name;
    bool _signedStatus;
    const int _gradeToSign;
    const int _gradeToExecute;
    const std::string _target;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
