#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << 
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{

}

Bureaucrat &Bureaucrat:: operator=(const Bureaucrat &obj)
{
    std::cout << this->name << ", bureaucrat grade " << this->grade << std::endl;
}

Bureaucrat:: ~Bureaucrat()
{

}

const std::string Bureaucrat:: getName()
{
    return (this->name);
}

const int Bureaucrat::getGrade()
{
    return (this->grade);
}

void  upGrade()
{

}

void  downGrade()
{

}
