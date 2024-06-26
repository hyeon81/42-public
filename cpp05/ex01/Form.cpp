#include "Form.hpp"

Form::Form(): name("default"), isSigned(false), signGrade(150), execGrade(150)
{
    std::cout << this->name << " is created" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade): name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
    if (this->signGrade < 1 || this->execGrade < 1)
        throw GradeTooHighException();       
    else if (this->signGrade > 150 || this->execGrade > 150)
        throw GradeTooLowException();
    else
        std::cout << this->name << " is created" << std::endl;
}

Form::Form(const Form &obj): name(obj.name), isSigned(obj.isSigned), signGrade(obj.signGrade), execGrade(obj.execGrade)
{
    std::cout << "Copy constructor called" << std::endl;
}

Form &Form:: operator=(const Form &obj)
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

Form:: ~Form()
{
    std::cout << this->name << " is destroyed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << "[name] " << obj.getName() << ", [isSigned] " << obj.getIsSigned() << \
    ", [signGrade] " << obj.getSignGrade() << ", [execGrade] " << obj.getExecGrade();
    return (os);
}

const std::string& Form::getName() const
{
    return (this->name);
}

const int& Form::getSignGrade() const
{
    if (this->signGrade < 1)
        throw GradeTooHighException();       
    else if (this->signGrade > 150)
        throw GradeTooLowException();
    return (this->signGrade);
}

const int& Form::getExecGrade() const
{
    if (this->execGrade < 1)
        throw GradeTooHighException();       
    else if (this->execGrade > 150)
        throw GradeTooLowException();
    return (this->execGrade);
}

int Form::getIsSigned() const
{
    return (this->isSigned);
}

void Form::beSigned(const Bureaucrat& bur)
{ 
    if (bur.getGrade() > this->signGrade)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Error: Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Error: Grade is too low";
}