#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    this->target = "default";
    std::cout << "[PresidentialPardonForm] is created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target, 25, 5)
{
    this->target = target;
    std::cout << "[PresidentialPardonForm] "  << this->target << "is created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj): AForm(obj)
{
    std::cout << "[PresidentialPardonForm] Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm:: operator=(const PresidentialPardonForm &obj)
{
    std::cout << "[PresidentialPardonForm] Copy assignment operator called" << std::endl;
    if (&obj != this)
    {
        this->target = obj.target;
    }
    return (*this);
}

PresidentialPardonForm:: ~PresidentialPardonForm()
{
    std::cout << "[PresidentialPardonForm] " << this->target << " is destroyed" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    try 
    {
        this->isExecutable(executor);
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    } catch (std::exception & e)
    {
        std::cerr << "[PresidentialPardonForm] " << e.what() << std::endl;
        throw;
    }
}