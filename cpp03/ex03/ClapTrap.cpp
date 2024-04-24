#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 10;
    std::cout << "[ClapTrap] is created" << std::endl;
};

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 10;
    std::cout << "[ClapTrap] " << this->name << " is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    this->hitPoint = obj.hitPoint;
    this->energyPoint = obj.energyPoint;
    this->attackDamage = obj.attackDamage;
}

ClapTrap &ClapTrap:: operator=(const ClapTrap &obj)
{
    if (this == &obj)
        return (*this); 
    this->hitPoint = obj.hitPoint;
    this->energyPoint = obj.energyPoint;
    this->attackDamage = obj.attackDamage;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "[ClapTrap] " << this->name << " is destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energyPoint > 0 && this->hitPoint > 0)
    {
        std::cout << "[ClapTrap] " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoint -= 1;
    }
    else
        std::cout << "[ClapTrap] " << this->name << " can't attack: it doesn't have energy or hit point..." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->energyPoint > 0 && this->hitPoint > 0)
    {
        std::cout << "[ClapTrap] " << this->name << " is attacked. it loses " << amount << " hit points" << std::endl;
        this->hitPoint -= amount;
    }
    else
        std::cout << "[ClapTrap] " << this->name << "doesn't have energy or hit point..." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoint > 0 && this->hitPoint > 0)
    {
        std::cout << "[ClapTrap] " << this->name << " is repaired. it gets " << amount << " hit points" << std::endl;
        this->hitPoint += amount;
        this->energyPoint -= 1;
    }
    else
        std::cout << "[ClapTrap] " << this->name << " can't be repaired: it doesn't have energy or hit point..." << std::endl;
}

void ClapTrap::getInfo()
{
    std::cout << "[info] name: " << this->name << " | hitPoint: " << this->hitPoint 
    << " | energyPoint: " << this->energyPoint << " | attackDamage: " << this->attackDamage << std::endl;
}