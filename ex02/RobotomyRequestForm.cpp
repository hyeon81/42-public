#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    this->target = "default";
    std::cout << "[RobotomyRequestForm] is created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target, 72, 45)
{
    this->target = target;
    std::cout << "[RobotomyRequestForm] "  << this->target << "is created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj): AForm(obj)
{
    std::cout << "[RobotomyRequestForm] Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm:: operator=(const RobotomyRequestForm &obj)
{
    std::cout << "[RobotomyRequestForm] Copy assignment operator called" << std::endl;
    if (&obj != this)
    {
        this->target = obj.target;
    }
    return (*this);
}

RobotomyRequestForm:: ~RobotomyRequestForm()
{
    std::cout << "[RobotomyRequestForm] " << this->target << " is destroyed" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    try 
    {
        this->isExecutable(executor);
        std::cout << "make Drill..." << std::endl;
        int random = rand() % 10;
        std::cout << "random: " << random << std::endl;
        if (random > 5)
            throw RobotoMyFailedException();
        std::cout << this->target << " has been robotomized successfully 50% of the time" << std::endl;
    } catch (std::exception & e)
    {
        std::cerr << "[RobotomyRequestForm] " << e.what() << std::endl;
        throw;
    }
}
