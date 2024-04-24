 #ifndef FORM
 #define FORM

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
    private:
        Form();
        Form &operator=(const Form &obj);
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
        class GradeTooHighException : public std::exception
        {
            public:
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
            const char * what() const throw();
        };

    public:
        Form(std::string name, int signGrade, int execGrade);
        Form(const Form &obj);
        ~Form();
        const std::string& getName() const;
        const int &getSignGrade() const;
        const int &getExecGrade() const;
        int getIsSigned() const;
        void beSigned(const Bureaucrat& bur);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

 #endif