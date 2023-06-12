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
        if (this->grade < 1 || this->grade > 150)
            throw std::out_of_range("Grade must be 1-150");
        std::cout << this->name << " is created. grade is " << this->grade << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj):Bureaucrat(obj.name, obj.grade)
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
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return (os);
}

const std::string Bureaucrat:: getName() const
{
    return (this->name);
}

const int Bureaucrat::getGrade() const
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
    }
    catch (GradeTooHighException & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void  Bureaucrat::downGrade()
{
    try
    {
        if (this->grade >= 150)
            throw GradeTooLowException();
        this->grade++;
    }
    catch (GradeTooLowException & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

