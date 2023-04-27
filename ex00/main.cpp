#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "====new Animal()====" << std::endl;
    const Animal* meta = new Animal();
    std::cout << "====new Dog()====" << std::endl;
    const Animal* j = new Dog();
    std::cout << "====new Cat()====" << std::endl;
    const Animal* i = new Cat();

    std::cout << "====meta->getType()====" << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    std::cout << "====j->getType()====" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << "====i->getType()====" << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << "====j->makeSound()====" << std::endl;
    j->makeSound();
    std::cout << "====i->makeSound()====" << std::endl;
    i->makeSound();
    std::cout << "====meta->makeSound()====" << std::endl;
    meta->makeSound();
    std::cout << "====delete_All()====" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << std::endl;
    std::cout << "====new WrongAnimal()====" << std::endl;
    const WrongAnimal* meta2 = new WrongAnimal();
    std::cout << "====new WrongCat()====" << std::endl;
    const WrongAnimal* i2 = new WrongCat();
    std::cout << "====meta2->getType()====" << std::endl;
    std::cout << meta2->getType() << " " << std::endl;
    std::cout << "====i2->getType()====" << std::endl;
    std::cout << i2->getType() << " " << std::endl;
    std::cout << "====i2->makeSound()====" << std::endl;
    i2->makeSound();
    std::cout << "====meta->makeSound()====" << std::endl;
    meta2->makeSound();
    std::cout << "====delete_All()====" << std::endl;
    delete meta2;
    delete i2;

    return (0);
}
