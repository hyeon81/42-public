#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm: public AForm {
    private:
        RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
        class RobotoMyFailedException : public std::exception
        {
            public:
            const char* what() const throw() 
            {
                return "Error: Robotomy is Failed...";
            }
        };
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &obj);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
};

#endif