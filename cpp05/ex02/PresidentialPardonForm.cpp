#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm()
{
    this->target = "default";
    std::cout << "[PresidentialPardonForm] is created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardon", 25, 5)
{
    this->target = target;
    std::cout << "[PresidentialPardonForm] "  << this->target << " is created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj): AForm(obj)
{
    this->target = obj.getTarget();
    std::cout << "[PresidentialPardonForm] Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm:: operator=(const PresidentialPardonForm &obj)
{
    std::cout << "[PresidentialPardonForm] Copy assignment operator called" << std::endl;
    if (&obj != this)
    {
        setIsSigned(obj.getIsSigned());
        this->target = obj.getTarget();
    }
    return (*this);
}

PresidentialPardonForm:: ~PresidentialPardonForm()
{
    std::cout << "[PresidentialPardonForm] " << this->target << " is destroyed" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsSigned())
        throw NotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}