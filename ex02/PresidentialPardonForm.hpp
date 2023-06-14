#ifdef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"
class PresidentialPardonForm {
    private:
        PresidentialPardonForm();
        AForm &form;
    public:
        PresidentialPardonForm(std::string name, int signGrade, int execGrade);
        PresidentialPardonForm(const PresidentialPardonForm &obj);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
        ~PresidentialPardonForm();
        std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        int getIsSigned() const;
        virtual void beSigned(const Bureaucrat& bur) = 0;
};

#endif