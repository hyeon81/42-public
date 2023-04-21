#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
    std::cout << "[FragTrap] is created" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->name = name;
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
    std::cout << "[FragTrap] " << this->name << " is created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj)
{
    this->hitPoint = obj.hitPoint;
    this->energyPoint = obj.energyPoint;
    this->attackDamage = obj.attackDamage;
}

FragTrap &FragTrap:: operator=(const FragTrap &obj)
{
    if (this == &obj)
        return (*this); 
    this->hitPoint = obj.hitPoint;
    this->energyPoint = obj.energyPoint;
    this->attackDamage = obj.attackDamage;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "[FragTrap] " << this->name << " is destroyed" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (this->energyPoint > 0 && this->hitPoint > 0)
    {
        std::cout << "[FragTrap] " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoint -= 1;
    }
    elsea
        std::cout << "[FragTrap] " << this->name << " can't attack: it doesn't have energy or hit point..." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "[FragTrap] " << this->name << " gives a high five" << std::endl;
}
