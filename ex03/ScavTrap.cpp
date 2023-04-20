#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap is created" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " is created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
    this->hitPoint = obj.hitPoint;
    this->energyPoint = obj.energyPoint;
    this->attackDamage = obj.attackDamage;
}

ScavTrap &ScavTrap:: operator=(const ScavTrap &obj)
{
    if (this == &obj)
        return (*this); 
    this->hitPoint = obj.hitPoint;
    this->energyPoint = obj.energyPoint;
    this->attackDamage = obj.attackDamage;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " is destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is in Gatekeeper mode now" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->energyPoint > 0 && this->hitPoint > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoint -= 1;
    }
    else
        std::cout << "ScavTrap " << this->name << " can't attack: it doesn't have energy or hit point..." << std::endl;
}