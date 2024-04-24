#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    this->target = "default";
    std::cout << "[RobotomyRequestForm] is created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequest", 72, 45)
{
    this->target = target;
    std::cout << "[RobotomyRequestForm] "  << this->target << "is created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj): AForm(obj)
{
    this->target = obj.getTarget();
    std::cout << "[RobotomyRequestForm] Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm:: operator=(const RobotomyRequestForm &obj)
{
    std::cout << "[RobotomyRequestForm] Copy assignment operator called" << std::endl;
    if (&obj != this)
    {
        setIsSigned(obj.getIsSigned());
        this->target = obj.getTarget();
    }
    return (*this);
}

RobotomyRequestForm:: ~RobotomyRequestForm()
{
    std::cout << "[RobotomyRequestForm] " << this->target << " is destroyed" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw NotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    std::cout << "make Drill..." << std::endl;
    srand(time(NULL));
    int random = rand() % 100;
    if (random > 50)
        std::cout << this->target << " hasn't been robotomized...:(" << std::endl;
    else
        std::cout << this->target << " has been robotomized successfully 50% of the time" << std::endl;
}
