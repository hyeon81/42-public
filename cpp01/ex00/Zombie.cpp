#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    this->name = name;
    std::cout << this->name << " is created" << std::endl;
}

Zombie::Zombie() {}

Zombie::~Zombie()
{
    std::cout << this->name << " is destoryed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ…" << std::endl;
}
