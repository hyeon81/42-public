#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150)
{
    std::cout << this->name << " is created. grade is " << this->grade << std::endl;
}

//Constructor
Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade)
{
    try
    {
        if (this->grade < 1)
            throw GradeTooHighException();       
        else if (this->grade > 150)
            throw GradeTooLowException();
        else
            std::cout << this->name << " is created. grade is " << this->grade << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        throw e; 
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.name), grade(obj.grade)
{
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat:: operator=(const Bureaucrat &obj)
{
    std::cout << this->name << ", bureaucrat grade " << this->grade << std::endl;
    if (&obj != this)
    {
        this->grade = obj.grade;
    }
    return (*this);
}

Bureaucrat:: ~Bureaucrat()
{
    std::cout << this->name << " is destroyed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return (os);
}

std::string Bureaucrat:: getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void  Bureaucrat::upGrade()
{
    try
    {
        if (this->grade <= 1)
            throw GradeTooHighException();
        this->grade--;
        std::cout << this->name << " grade is up. now is " << this->grade << std::endl;
    }
    catch (GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
        throw e; 
    }
}

void  Bureaucrat::downGrade()
{
    try
    {
        if (this->grade >= 150)
            throw GradeTooLowException();
        this->grade++;
        std::cout << this->name << " grade is down. now is " << this->grade << std::endl;
    }
    catch (GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;
        throw e; 
    }
}
