#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap is created" << std::endl;
};

ClapTrap::ClapTrap(std::string name): name(name)
{
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 10;
    std::cout << "ClapTrap " << this->name << " is created" << std::endl;
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
    std::cout << "ClapTrap " << this->name << " is destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energyPoint > 0 && this->hitPoint > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoint -= 1;
    }
    else
        std::cout << "ClapTrap " << this->name << " can't attack: it doesn't have energy or hit point..." << std::endl;
}
