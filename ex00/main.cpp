#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "====new Animal()====" << std::endl;
    const Animal* meta = new Animal();
    std::cout << "====new Dog()====" << std::endl;
    const Animal* j = new Dog();
    std::cout << "====new Cat()====" << std::endl;
    const Animal* i = new Cat();

    std::cout << "====j->getType()====" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << "====i->getType()====" << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << "====i->makeSound()====" << std::endl;
    i->makeSound(); //will output the cat sound!
    std::cout << "====j->makeSound()====" << std::endl;
    j->makeSound();
    std::cout << "====meta->makeSound()====" << std::endl;
    meta->makeSound();

    //delete는 안해줘도 되남
    return (0);
}
