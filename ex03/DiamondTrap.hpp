#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
    protected: 
        std::string name;
        int hitPoint;
        int energyPoint;
        int attackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &obj);
        ClapTrap &operator=(const ClapTrap &obj);
        ~ClapTrap();

        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void getInfo();
};

#endif
