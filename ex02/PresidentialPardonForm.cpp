#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    std::cout << this->name << " is created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
    if (this->signGrade < 1 || this->execGrade < 1)
        throw GradeTooHighException();       
    else if (this->signGrade > 150 || this->execGrade > 150)
        throw GradeTooLowException();
    else
        std::cout << this->name << " is created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj): name(obj.name), isSigned(obj.isSigned), signGrade(obj.signGrade), execGrade(obj.execGrade)
{
    std::cout << "Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm:: operator=(const PresidentialPardonForm &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (&obj != this)
    {
        this->isSigned = obj.isSigned;
        // this->signGrade = obj.signGrade;
        // this->execGrade = obj.execGrade;
    }
    return (*this);
}

PresidentialPardonForm:: ~PresidentialPardonForm()
{
    std::cout << this->name << " is destroyed" << std::endl;
}
