#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {
    private:
        const std::string name;
        int  grade; //1~150
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        const std::string getName();
        const int getGrade();
        void  upGrade();
        void  downGrade();
};

#endif