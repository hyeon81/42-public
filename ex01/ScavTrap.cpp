#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
    std::cout << "ScavTrap is created" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " is created" << std::endl;
}
