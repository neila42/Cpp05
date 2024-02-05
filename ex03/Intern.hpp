#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
public:
    Intern();
    virtual ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target) const;

private:
    struct FormCreationEntry {
        std::string name;
        AForm* (*createFunc)(const std::string&);
    };

    static AForm* createPresidentialPardonForm(const std::string& target);
    static AForm* createRobotomyRequestForm(const std::string& target);
    static AForm* createShrubberyCreationForm(const std::string& target);

    static const FormCreationEntry formCreationTable[];
};

#endif
