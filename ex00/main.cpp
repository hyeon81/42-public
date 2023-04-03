#include "Zombie.hpp"

int main(void)
{
    Zombie stackZombie("stack");
    Zombie *heapZombie = newZombie("heap");

    stackZombie.announce();
    randomChump("stack2");
    heapZombie->announce();
    delete heapZombie;
    
    return (0);
}
