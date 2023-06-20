#ifndef INTERN
#define INTERN

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
    public:
        class NonexistentTypeException : public std::exception
        {
            public:
            const char* what() const throw();
        };
        Intern();
        Intern(const Intern &obj);
        Intern &operator=(const Intern &obj);
        ~Intern();
        AForm* makeForm(std::string name, std::string target);
        AForm* returnPresidentialPardonForm(std::string name);
        AForm* returnRobotomyRequestForm(std::string name);
        AForm* returnShrubberyCreationForm(std::string name);
};

#endif
