#include "Zombie.hpp"

void    do_test()
{
    Zombie stackZombie("stack");
    Zombie *heapZombie = newZombie("heap");

    stackZombie.announce();
    randomChump("stack2");
    heapZombie->announce();
}

int main(void)
{
    do_test();
    system("leaks Zombie");
}
