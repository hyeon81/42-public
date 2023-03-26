#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
    private:
        Weapon *weapon;
        std::string name;
    public:
        void attack();
        void setWeapon(Weapon &weapon);
        HumanB(std::string name);
        ~HumanB();
};

#endif
