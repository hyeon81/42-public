#include "Zombie.hpp"

int main(void)
{
    Zombie *zombies;
    int i = 0;

    zombies = zombieHorde(5, "zombie!");
    while (i < 5)
    {
        zombies[i].announce();
        i++;
    }
    delete[] zombies;
}
