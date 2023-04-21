#include "FragTrap.hpp"

int main()
{
    ClapTrap a("a");
    FragTrap b("b");

    a.getInfo();
    b.getInfo();
    std::cout << std::endl;    
    a.takeDamage(3);
    a.attack("someone");
    a.beRepaired(5);
    std::cout << std::endl;    
    b.takeDamage(2);
    b.attack("someone");
    b.highFivesGuys();

    return (0);
}
