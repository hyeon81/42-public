#include "Bureaucrat.hpp"

int main()
{
    try {
            // Bureaucrat 객체 생성
    std::cout << "======== create =========" << std::endl;
    Bureaucrat grade100("grade100", 100);
    Bureaucrat grade1("grade1", 1);
    Bureaucrat grade150("grade150", 150);
    Bureaucrat grade0("grade0", 0);
    Bureaucrat grade151("grade151", 151);

    std::cout << "======== print =========" << std::endl;
    std::cout << grade100 << std::endl;
    std::cout << grade1 << std::endl;
    std::cout << grade150 << std::endl;
    std::cout << grade0 << std::endl;
    std::cout << grade151 << std::endl;

    // 등급 조정
    std::cout << "======== upGrade =========" << std::endl;
    grade100.upGrade();
    grade1.upGrade();
    grade150.upGrade();
    grade0.upGrade();
    grade151.upGrade();

    std::cout << "======== downGrade =========" << std::endl;
    grade100.downGrade();
    grade1.downGrade();
    grade150.downGrade();
    grade0.downGrade();
    grade151.downGrade();
    
    std::cout << "======== print =========" << std::endl;
    std::cout << grade100 << std::endl;
    std::cout << grade1 << std::endl;
    std::cout << grade150 << std::endl;
    std::cout << grade0 << std::endl;
    std::cout << grade151 << std::endl;

    } catch (std::exception &e)
    {
        std::cerr << "<main> " << e.what() << std::endl;
    }
    std::cout << "======== end =========" << std::endl;
    return 0;
}