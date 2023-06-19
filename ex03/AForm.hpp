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
        AForm &operator=(const AForm &obj);

    protected:
        AForm();
        std::string target;
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
        class NotSignedException : public std::exception
        {
            public:
            const char * what() const throw();
        };

    public:
        AForm(std::string name, int signGrade, int execGrade);
        AForm(const AForm &obj);
        virtual ~AForm();
        const std::string &getName() const;
        const int &getSignGrade() const;
        const int &getExecGrade() const;
        bool getIsSigned() const;
        const std::string &getTarget() const;
        void beSigned(const Bureaucrat& bur);
        virtual void execute(Bureaucrat const & executor) const = 0;
        void setIsSigned(bool isSigned);
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

 #endif