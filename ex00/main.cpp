#include "Bureaucrat.hpp"

int main()
{
    try {
            std::cout << "======== normal =========" << std::endl;
            Bureaucrat grade100("grade100", 100);
            std::cout << grade100 << std::endl;
            grade100.upGrade();
            grade100.downGrade();
            std::cout << grade100 << std::endl;

            std::cout << "======== minimal =========" << std::endl;
            Bureaucrat grade1("grade1", 1);
            std::cout << grade1 << std::endl;
            grade1.upGrade();
            grade1.downGrade();
            std::cout << grade1 << std::endl;

            std::cout << "======== maximum =========" << std::endl;
            Bureaucrat grade150("grade150", 150);
            std::cout << grade150 << std::endl;
            grade150.downGrade();
            grade150.upGrade();
            std::cout << grade150 << std::endl;

            // std::cout << "======== error =========" << std::endl;
            // Bureaucrat grade0("grade0", 0);
            // std::cout << grade0 << std::endl;
            // grade0.upGrade();
            // grade0.downGrade();
            // std::cout << grade0 << std::endl;

            std::cout << "======== error =========" << std::endl;
            Bureaucrat grade151("grade151", 151);
            std::cout << grade151 << std::endl;
            grade151.upGrade();
            grade151.downGrade();
            std::cout << grade151 << std::endl;

    } catch (std::exception &e) {
        std::cerr << "[main] " << e.what() << std::endl;
    }
    std::cout << "======== end =========" << std::endl;
    return 0;
}