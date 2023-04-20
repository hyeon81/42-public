#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("a");
    ClapTrap b("b");

    a.takeDamage(10);
    a.attack("someone");
    a.beRepaired(2);    
    b.takeDamage(-2); //unsigned int 방지...
    b.attack("someone");

    return (0);
}