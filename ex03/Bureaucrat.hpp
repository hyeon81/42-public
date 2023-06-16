#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
        Bureaucrat();
        const std::string name;
        int  grade;

        class GradeTooHighException : public std::exception
        {
            public:
            const char* what() const throw() 
            {
                return "Error: Grade can't be higher than 1";
            }
        };

        class GradeTooLowException : public std::exception
        {
            public:
            const char * what() const throw() 
            {
                return "Error: Grade can't be less than 150";
            }
        };

    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        std::string getName() const;
        int   getGrade() const;
        void  upGrade();
        void  downGrade();
        void  signForm(AForm &form);
        void  executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif