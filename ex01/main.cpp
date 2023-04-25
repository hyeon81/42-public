#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal *arr = new Animal[10];
    
    for (int i = 0; i < 5; i++)
        arr[i] = new Dog();
    for (int i = 0; i < 5; i++)
        arr[i] = new Cat();
    std::cout << "====const Animal* j = new Dog()====" << std::endl;
    const Animal* j = new Dog();
    std::cout << "====const Animal* i = new Cat()====" << std::endl;
    const Animal* i = new Cat();
    std::cout << "====delete j====" << std::endl;
    delete j;//should not create a leak
    std::cout << "====delete i====" << std::endl;
    delete i;
    while(1);

    return 0;
}
