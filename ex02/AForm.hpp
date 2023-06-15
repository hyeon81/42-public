 #ifndef AFORM
 #define AFORM

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
    private:
        AForm();
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
        AForm(std::string name, int signGrade, int execGrade);
        AForm(const AForm &obj);
        AForm &operator=(const AForm &obj);
        ~AForm();
        std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        int getIsSigned() const;
        void beSigned(const Bureaucrat& bur);
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

 #endif