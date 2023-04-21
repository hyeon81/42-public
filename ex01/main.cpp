#include "ScavTrap.hpp"

int main()
{
    ClapTrap a("a");
    ScavTrap b("b");
    std::cout << std::endl;    
    a.getInfo();
    b.getInfo();
    std::cout << std::endl;    
    a.takeDamage(3);
    a.getInfo();
    a.attack("someone");
    a.getInfo();
    a.beRepaired(5);
    a.getInfo();
    std::cout << std::endl;    
    b.takeDamage(2);
    b.getInfo();
    b.attack("someone");
    b.getInfo();
    b.guardGate();
    b.getInfo();
    std::cout << std::endl;    

    return (0);
}
