#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

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
        void  signForm(Form &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif