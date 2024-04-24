#include "Zombie.hpp"

int main(void)
{
    Zombie stackZombie("stack1");
    Zombie *heapZombie = newZombie("heap");

    heapZombie->announce();
    stackZombie.announce();
    randomChump("stack2");
    randomChump("stack3");
    delete heapZombie;
    
    return (0);
}
