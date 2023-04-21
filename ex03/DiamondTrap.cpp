#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "[DiamondTrap] is created" << std::endl;
};

DiamondTrap::DiamondTrap(std::string name)
{
    hitPoint = FragTrap::hitPoint;
    energyPoint = ScavTrap::energyPoint;
    attackDamage = FragTrap::attackDamage;
    
    this->name = name;
    ClapTrap::name = name + "_clap_name";
    std::cout << "[DiamondTrap] " << this->name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj)
{
    this->hitPoint = obj.hitPoint;
    this->energyPoint = obj.energyPoint;
    this->attackDamage = obj.attackDamage;
}

DiamondTrap &DiamondTrap:: operator=(const DiamondTrap &obj)
{
    if (this == &obj)
        return (*this); 
    this->hitPoint = obj.hitPoint;
    this->energyPoint = obj.energyPoint;
    this->attackDamage = obj.attackDamage;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "[DiamondTrap] " << this->name << " is destroyed" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "[DiamondTrap::whoAmI] my name is "<< this->name << " and ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    FragTrap::attack(target);
}