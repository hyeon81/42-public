#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm {
    private:
        ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
        class FileOpenFailedException : public std::exception
        {
            public:
            const char* what() const throw() 
            {
                return "Error: File Open is Failed";
            }
        };
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
};

#endif
