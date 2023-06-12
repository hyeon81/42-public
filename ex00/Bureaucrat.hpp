#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class GradeTooHighException : public std::exception
{
    public:
        const char * what() const noexcept override
        {
            return "Error: Grade can't be higher than 1";
        }
};

class GradeTooLowException : public std::exception
{
    public:
        const char * what() const noexcept override
        {
            return "Error: Grade can't be less than 150";
        }
};

class Bureaucrat {
    private:
        Bureaucrat();
        const std::string name;
        int  grade; //1~150
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        const std::string getName() const;
        const int getGrade() const;
        void  upGrade();
        void  downGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif