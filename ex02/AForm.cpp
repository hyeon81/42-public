#include "AForm.hpp"

AForm::AForm(): name("default"), isSigned(false), signGrade(150), execGrade(150)
{
    std::cout << "[AForm] " << this->name << " is created" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade): name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
    if (this->signGrade < 1 || this->execGrade < 1)
        throw GradeTooHighException();       
    else if (this->signGrade > 150 || this->execGrade > 150)
        throw GradeTooLowException();
    else
        std::cout << "[AForm] " << this->name << " is created" << std::endl;
}

AForm::AForm(const AForm &obj): name(obj.name), isSigned(obj.isSigned), signGrade(obj.signGrade), execGrade(obj.execGrade)
{
    std::cout << "Copy constructor called" << std::endl;
}

AForm &AForm:: operator=(const AForm &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (&obj != this)
    {
        this->isSigned = obj.isSigned;
        (const_cast<std::string&>(this->name)) = obj.getName();
        (const_cast<int&>(this->signGrade)) = obj.getSignGrade();
        (const_cast<int&>(this->execGrade)) = obj.getExecGrade();
    }
    return (*this);
}

AForm:: ~AForm()
{
    std::cout << "[AForm] " << this->name << " is destroyed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << "[name] " << obj.getName() << ", [isSigned] " << obj.getIsSigned() << \
    ", [signGrade] " << obj.getSignGrade() << ", [execGrade] " << obj.getExecGrade();
    return (os);
}

const std::string &AForm:: getName() const
{
    return (this->name);
}

const int &AForm::getSignGrade() const
{
    if (this->signGrade < 1)
        throw GradeTooHighException();       
    else if (this->signGrade > 150)
        throw GradeTooLowException();
    return (this->signGrade);
}

const int &AForm::getExecGrade() const
{
    if (this->execGrade < 1)
        throw GradeTooHighException();       
    else if (this->execGrade > 150)
        throw GradeTooLowException();
    return (this->execGrade);
}

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

void AForm::beSigned(const Bureaucrat& bur)
{ 
    if (bur.getGrade() > this->signGrade)
        throw GradeTooLowException();
    this->isSigned = true;
}

void AForm::isExecutable(const Bureaucrat& executor) const
{
    if (!this->getIsSigned())
        throw NotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
}

std::string &AForm::getTarget() const
{
    return (this->target);
}