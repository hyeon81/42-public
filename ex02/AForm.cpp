#include "AForm.hpp"

AForm::AForm(): name("default"), isSigned(false), signGrade(150), execGrade(150)
{
    std::cout << this->name << " is created" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade): name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
    if (this->signGrade < 1 || this->execGrade < 1)
        throw GradeTooHighException();       
    else if (this->signGrade > 150 || this->execGrade > 150)
        throw GradeTooLowException(); //예외처리할때 메세지 못던지나?
    else
        std::cout << this->name << " is created" << std::endl;
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
        // this->signGrade = obj.signGrade;
        // this->execGrade = obj.execGrade;
    }
    return (*this);
}

AForm:: ~AForm()
{
    std::cout << this->name << " is destroyed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << "[name] " << obj.getName() << ", [isSigned] " << obj.getIsSigned() << \
    ", [signGrade] " << obj.getSignGrade() << ", [execGrade] " << obj.getExecGrade();
    return (os);
}

std::string AForm:: getName() const
{
    return (this->name);
}

int AForm::getSignGrade() const
{
    if (this->signGrade < 1)
        throw GradeTooHighException();       
    else if (this->signGrade > 150)
        throw GradeTooLowException();
    return (this->signGrade);
}

int AForm::getExecGrade() const
{
    if (this->execGrade < 1)
        throw GradeTooHighException();       
    else if (this->execGrade > 150)
        throw GradeTooLowException();
    return (this->execGrade);
}

int AForm::getIsSigned() const
{
    return (this->isSigned);
}

void AForm::beSigned(const Bureaucrat& bur)
{ 
    if (bur.getGrade() > this->signGrade)
        throw GradeTooLowException();
    this->isSigned = true;
}