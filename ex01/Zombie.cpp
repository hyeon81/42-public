#include "Zombie.hpp"

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie::Zombie(std::string name): name(name){}

Zombie::~Zombie()
{
    std::cout << this->name << " is destoryed!!" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ…" << std::endl;
}
