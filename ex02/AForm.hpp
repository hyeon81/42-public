 #ifndef AFORM
 #define AFORM

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;

    protected:
        AForm();
        AForm &operator=(const AForm &obj);
        std::string target;
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
        class NotSignedException : public std::exception
        {
            public:
            const char * what() const throw() 
            {
                return "Error: Form is Not Signed";
            }
        };

    public:
        AForm(std::string name, int signGrade, int execGrade);
        AForm(const AForm &obj);
        virtual ~AForm();
        const std::string &getName() const;
        const int &getSignGrade() const;
        const int &getExecGrade() const;
        bool getIsSigned() const;
        std::string &getTarget() const;
        void beSigned(const Bureaucrat& bur);
        void isExecutable(const Bureaucrat& executor) const;
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

 #endif