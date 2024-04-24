#include "Form.hpp"

int main()
{
    try {
        std::cout << "======== success =========" << std::endl;
        Form form100("form100", 100, 100);
        std::cout << form100 << std::endl;
        Bureaucrat grade100("grade100", 100);
        grade100.signForm(form100);

        // std::cout << "======== form grade wrong =========" << std::endl;
        // Form form151("form151", 151, 151);
        // std::cout << form151 << std::endl;
        // grade100.signForm(form151);

        // std::cout << "======== form grade not enough =========" << std::endl;
        Form form50("form50", 50, 50);
        // std::cout << form50 << std::endl;
        // grade100.signForm(form50);

        std::cout << "======== form grade not enough =========" << std::endl;
        // form100.beSigned(grade100);
        form50.beSigned(grade100);
        //만약 이미 Form이 signed 되어있다면?
    } catch (std::exception &e) {
        std::cerr << "[main] " << e.what() << std::endl;
    }
    std::cout << "======== end =========" << std::endl;
    return 0;
}
