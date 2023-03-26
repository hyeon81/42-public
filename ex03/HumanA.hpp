#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
    private:
        std::string name;
        Weapon &weapon;
    public:
        HumanA(std::string name, Weapon &weapon);
        void attack();
        void setWeapon(Weapon &weapon);
        ~HumanA();
};

#endif