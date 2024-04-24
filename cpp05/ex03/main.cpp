#include "Intern.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        Bureaucrat a("a", 1);
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        a.signForm(*rrf);
        a.executeForm(*rrf);
        rrf = someRandomIntern.makeForm("hello", "Bender");
    }catch (std::exception &e)
    {
        std::cerr << "exception occurs: " << e.what() << std::endl;
    }
    return 0;
}
