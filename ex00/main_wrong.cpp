#include "WrongCat.hpp"

int main()
{
    std::cout << "====new Animal()====" << std::endl;
    const WrongAnimal* meta = new WrongAnimal();
    std::cout << "====new Cat()====" << std::endl;
    const WrongAnimal* i = new WrongCat();

    std::cout << "====i->getType()====" << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << "====i->makeSound()====" << std::endl;
    i->makeSound(); //will output the cat sound!
    std::cout << "====meta->makeSound()====" << std::endl;
    meta->makeSound();

    //delete는 안해줘도 되남
    return (0);
}
