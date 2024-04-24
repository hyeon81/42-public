#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"
#include <stdlib.h>
#include <time.h>

class RobotomyRequestForm: public AForm {
    private:
        RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &obj);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
};

#endif