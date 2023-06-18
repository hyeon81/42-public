#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &obj);
        const std::string name;
        int  grade;

    public:
        class GradeTooHighException : public std::exception
        {
            public:
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
            const char* what() const throw();
        };

        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        ~Bureaucrat();
        const std::string& getName() const;
        int &getGrade() const;
        void  upGrade();
        void  downGrade();
        void  signForm(Form &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif