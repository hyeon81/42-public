#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "[Intern] is created" << std::endl;
}

Intern::Intern(const Intern &obj)
{
    *this = obj;
    std::cout << "[Intern] Copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &obj)
{
    std::cout << "[Intern] Copy assignment operator called" << std::endl;
    if (&obj != this)
        return (*this);
    return (*this);
}

Intern::~Intern()
{
    std::cout << "[Intern] is destroyed" << std::endl;
}

const char* Intern::NonexistentTypeException::what() const throw() {
    return "Error: Nonexistent Type";
}


AForm* Intern::returnPresidentialPardonForm(std::string name)
{
    return (new PresidentialPardonForm(name));
}

AForm* Intern::returnRobotomyRequestForm(std::string name)
{
    return new RobotomyRequestForm(name);
}

AForm* Intern::returnShrubberyCreationForm(std::string name)
{
    return new ShrubberyCreationForm(name);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string formName[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*funcs[3])(std::string target) = {&returnShrubberyCreationForm, &returnRobotomyRequestForm, &returnPresidentialPardonForm};

    for (int i = 0; i < 3; i++)
    {
        if (formName[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return funcs[i](target);
        }
    }
    throw Intern::NonexistentTypeException();
}

