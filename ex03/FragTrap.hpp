#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &obj);
        ScavTrap &operator=(const ScavTrap &obj);
        ~ScavTrap();
        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
