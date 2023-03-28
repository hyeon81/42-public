#include "Zombie.hpp"

int main(void)
{
    Zombie *zombies;
    int i = 0;

    zombies = zombieHorde(2, "zombie!");
    while (i < 2)
    {
        zombies[i].announce();
        i++;
    }
    delete[] zombies;
}
