#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    ShrubberyCreationForm sform("sform");
    try {
        std::cout << "======== ShrubberyCreationForm (145, 137) =========" << std::endl;
        std::cout << "======== sign level is low =========" << std::endl;
        Bureaucrat a("a", 150);
        a.signForm(sform);
        a.executeForm(sform);
        } catch (std::exception &e) {
        std::cerr << "[main] " << e.what() << std::endl;
    }
    try {
        std::cout << std::endl;
        std::cout << "======== exec level is low =========" << std::endl;
        Bureaucrat a("a", 145);
        a.signForm(sform);
        a.executeForm(sform);
        } catch (std::exception &e) {
        std::cerr << "[main] " << e.what() << std::endl;
    }
    try {
        std::cout << std::endl;
        std::cout << "======== exec success =========" << std::endl;
        Bureaucrat a("a", 130);
        a.signForm(sform);
        a.executeForm(sform);
        } catch (std::exception &e) {
        std::cerr << "[main] " << e.what() << std::endl;
    }

    RobotomyRequestForm rform("rform");
    try {
        std::cout << "======== RobotomyRequestForm (72, 45) =========" << std::endl;
        std::cout << "======== sign level is low =========" << std::endl;
        Bureaucrat a("a", 71);
        a.signForm(rform);
        a.executeForm(rform);
        } catch (std::exception &e) {
        std::cerr << "[main] " << e.what() << std::endl;
    }
    try {
        std::cout << std::endl;
        std::cout << "======== exec level is low =========" << std::endl;
        Bureaucrat a("a", 72);
        a.signForm(rform);
        a.executeForm(rform);
        a.signForm(rform);
        } catch (std::exception &e) {
        std::cerr << "[main] " << e.what() << std::endl;
    }
    try {
        std::cout << std::endl;
        std::cout << "======== exec success =========" << std::endl;
        Bureaucrat a("a", 45);
        a.signForm(rform);
        a.executeForm(rform);
        a.signForm(rform);
        } catch (std::exception &e) {
        std::cerr << "[main] " << e.what() << std::endl;
    }

    PresidentialPardonForm pform("pform");
    try {
        std::cout << "======== RobotomyRequestForm (25, 5) =========" << std::endl;
        std::cout << "======== sign level is low =========" << std::endl;
        Bureaucrat a("a", 30);
        a.signForm(pform);
        a.executeForm(pform);
        a.signForm(pform);
        } catch (std::exception &e) {
        std::cerr << "[main] " << e.what() << std::endl;
    }
    try {
        std::cout << std::endl;
        std::cout << "======== exec level is low =========" << std::endl;
        Bureaucrat a("a",  25);
        a.signForm(pform);
        a.executeForm(pform);
        a.signForm(pform);
        } catch (std::exception &e) {
        std::cerr << "[main] " << e.what() << std::endl;
    }
    try {
        std::cout << std::endl;
        std::cout << "======== exec success =========" << std::endl;
        Bureaucrat a("a", 5);
        a.signForm(pform);
        a.executeForm(pform);
        a.signForm(pform);
        } catch (std::exception &e) {
        std::cerr << "[main] " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "======== end =========" << std::endl;
    return 0;
}
