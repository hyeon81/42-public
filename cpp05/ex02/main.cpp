#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::cout << "======== ShrubberyCreationForm: Required grades: sign 145, exec 137 =========" << std::endl;
    std::cout << "======== sign level is low =========" << std::endl;
    ShrubberyCreationForm sform("sform");
    try {
        Bureaucrat a("a", 150);
        a.signForm(sform);
        a.executeForm(sform);
        } catch (std::exception &e) {
        std::cerr << "[main] " << e.what() << std::endl;
    }
    try {
        ShrubberyCreationForm sform2("sform2");
        std::cout << "======== exec level is low =========" << std::endl;
        Bureaucrat a("a", 140);
        a.signForm(sform2);
        a.executeForm(sform2);
    } catch (std::exception &e) {
    std::cerr << "[main] exception occurs" << std::endl;
    }
    try {
        std::cout << "======== not signed =========" << std::endl;
        Bureaucrat a("a", 130);
        a.executeForm(sform);
    } catch (std::exception &e) {
    std::cerr << "[main] exception occurs" << std::endl;
    }
    try {
        std::cout << std::endl;
        std::cout << "======== exec success =========" << std::endl;
        Bureaucrat a("a", 130);
        a.signForm(sform);
        a.executeForm(sform);
        } catch (std::exception &e) {
        std::cerr << "[main] exception occurs" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "======== RobotomyRequestForm: Required grades: sign 72, exec 45 =========" << std::endl;
    std::cout << "======== sign level is low =========" << std::endl;
    RobotomyRequestForm rform("rform");
    try {    

        Bureaucrat a("a", 71);
        a.signForm(rform);
        a.executeForm(rform);
        } catch (std::exception &e) {
        std::cerr << "[main] exception occurs" << std::endl;
    }
    try {
        std::cout << std::endl;
        std::cout << "======== exec level is low =========" << std::endl;
        Bureaucrat a("a", 72);
        a.signForm(rform);
        a.executeForm(rform);
        a.signForm(rform);
        } catch (std::exception &e) {
        std::cerr << "[main] exception occurs" << std::endl;
    }
    try {
        std::cout << std::endl;
        std::cout << "======== exec success =========" << std::endl;
        Bureaucrat a("a", 45);
        a.signForm(rform);
        a.executeForm(rform);
        a.signForm(rform);
        } catch (std::exception &e) {
        std::cerr << "[main] exception occurs" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "======== PresidentialPardonForm: Required grades: sign 25, exec 5 =========" << std::endl;
    std::cout << "======== sign level is low =========" << std::endl;
    PresidentialPardonForm pform("pform");
    try {
        Bureaucrat a("a", 30);
        a.signForm(pform);
        a.executeForm(pform);
        a.signForm(pform);
        } catch (std::exception &e) {
        std::cerr << "[main] exception occurs" << std::endl;
    }
    try {
        std::cout << std::endl;
        std::cout << "======== exec level is low =========" << std::endl;
        Bureaucrat a("a",  25);
        a.signForm(pform);
        a.executeForm(pform);
        a.signForm(pform);
        } catch (std::exception &e) {
        std::cerr << "[main] exception occurs" << std::endl;
    }
    try {
        std::cout << std::endl;
        std::cout << "======== exec success =========" << std::endl;
        Bureaucrat a("a", 5);
        a.signForm(pform);
        a.executeForm(pform);
        a.signForm(pform);
        } catch (std::exception &e) {
        std::cerr << "[main] exception occurs" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "======== end =========" << std::endl;
    return 0;
}
