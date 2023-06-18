#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150)
{
    std::cout << "[Bureaucrat] " << this->name << " is created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade)
{
    if (this->grade < 1)
        throw GradeTooHighException();       
    else if (this->grade > 150)
        throw GradeTooLowException();
    else
        std::cout << "[Bureaucrat] " << this->name << " is created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.name), grade(obj.grade)
{
    std::cout << "[Bureaucrat] Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat:: operator=(const Bureaucrat &obj)
{
    std::cout << "[Bureaucrat] Copy assignment operator called" << std::endl;
    if (&obj != this)
    {
        (const_cast<std::string&>(this->name)) = obj.getName();
        this->grade = obj.grade;
    }
    return (*this);
}

Bureaucrat:: ~Bureaucrat()
{
    std::cout << "[Bureaucrat] " << this->name << " is destroyed" << std::endl;
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
 if (this->grade < 1)
        throw GradeTooHighException();       
    else if (this->grade > 150)
        throw GradeTooLowException();
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
        std::cerr << "[upGrade] " << e.what() << std::endl;
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
        std::cerr << "[downGrade] " << e.what() << std::endl;
    }
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << "[Bureaucrat] " << this->name << " signed " << form.getName() << std::endl;
    } 
    catch (std::exception &e)
    {
        std::cerr << "[Bureaucrat] " << this->name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getTarget() << std::endl;
    } catch (std::exception &e)
    {
        std::cerr << "[Bureaucrat] " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Error: Grade can't be higher than 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Error: Grade can't be less than 150";
}