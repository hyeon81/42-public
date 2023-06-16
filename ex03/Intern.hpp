#ifndef INTERN
#define INTERN

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern &obj);
        Intern &operator=(const Intern &obj);
        ~Intern();
        Form* makeForm(std::string name, std::string target);
}

#endif
