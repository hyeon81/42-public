#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
    private:
        PresidentialPardonForm();
        PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
        class FileOpenFailedException : public std::exception
        {
            public:
            const char* what() const throw() 
            {
                return "Error: File Open is Failed";
            }
        };
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &obj);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const & executor) const;
};

#endif