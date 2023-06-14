 #ifndef FORM
 #define FORM

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
    private:
        Form();
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
        class GradeTooHighException : public std::exception
        {
            public:
            const char* what() const throw() 
            {
                return "Error: Grade is too high";
            }
        };

        class GradeTooLowException : public std::exception
        {
            public:
            const char * what() const throw() 
            {
                return "Error: Grade is too low";
            }
        };

    public:
        Form(std::string name, int signGrade, int execGrade);
        Form(const Form &obj);
        Form &operator=(const Form &obj);
        ~Form();
        std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        int getIsSigned() const;
        void beSigned(const Bureaucrat& bur);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

 #endif