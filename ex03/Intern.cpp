#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "[Intern] is created" << std::endl;
}

Intern::Intern(const Intern &obj)
{
    std::cout << "[Intern] Copy constructor called" << std::endl;
}

Intern::Intern &operator=(const Intern &obj)
{
    std::cout << "[Intern] Copy assignment operator called" << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "[Intern] is destroyed" << std::endl;
}

Form* Intern::makeForm(std::string name, std::string target)
{
    std::string formName[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    void (AForm::*funcs[3])(void) = {&AForm::ShrubberyCreationForm(target), &AForm::RobotomyRequestForm(target), &AForm::PresidentialPardonForm(target)};

    for (int i = 0; i < 3; i++)
    {
        if (formName[i] == name)
        {
            (this->*funcs[i])();
        }
    }
}