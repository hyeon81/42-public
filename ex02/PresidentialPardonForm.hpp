#ifdef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"
class PresidentialPardonForm: public AForm {
    private:
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &obj);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
        ~PresidentialPardonForm();
};

#endif