#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap b("b");
    std::cout << std::endl;    
    b.getInfo();
    std::cout << std::endl;    
    b.takeDamage(2);
    b.attack("someone");
    b.whoAmI();
    b.getInfo();
    std::cout << std::endl;    

    return (0);
}
