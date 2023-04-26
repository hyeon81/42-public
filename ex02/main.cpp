#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "====basic test====" << std::endl;
    // std::cout << "====new Animal()====" << std::endl;
    // const Animal* meta = new Animal();
    std::cout << "====const Animal* j = new Dog()====" << std::endl;
    const Animal* j = new Dog();
    std::cout << "====const Animal* i = new Cat()====" << std::endl;
    const Animal* i = new Cat();
    std::cout << std::endl;

    std::cout << "====j->getType()====" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << "====i->getType()====" << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << "====i->makeSound()====" << std::endl;
    i->makeSound();
    std::cout << "====j->makeSound()====" << std::endl;
    j->makeSound();
    // std::cout << "====meta->makeSound()====" << std::endl;
    // meta->makeSound();
        std::cout << "====delete j====" << std::endl;
    delete j;
    std::cout << "====delete i====" << std::endl;
    delete i;
    std::cout << std::endl;

    std::cout << "====Animal array test====" << std::endl;
    std::cout << "====Animal *arr[10]====" << std::endl;
    Animal *arr[10];
    std::cout << "====arr[i] = new Dog()====" << std::endl;
    for (int i = 0; i < 5; i++)
        arr[i] = new Dog();
    std::cout << "====arr[i] = new Cat()====" << std::endl;
    for (int i = 5; i < 10; i++)
        arr[i] = new Cat();
    std::cout << "====arr[i]->makeSound()====" << std::endl;
    for (int i = 0; i < 10; i++)
        arr[i]->makeSound();
    for(int i = 0; i < 10; i++)
    {
        std::cout << "====delete arr ["<< i << "]====" << std::endl;
        delete arr[i];
    }
    std::cout << std::endl;

    std::cout << "====[Dog] copy constructor test====" << std::endl;
    std::cout << "====Dog a====" << std::endl;
    Dog a;
    a.setBrain("hello");
    a.showBrain();
    std::cout << "====Dog b(a)====" << std::endl;
    Dog b(a); //복사생성자 생성.
    b.setBrain("world");
    b.showBrain();
    a.showBrain();
    std::cout << "====a = b====" << std::endl;    
    a = b;
    a.showBrain();
    b.showBrain();

    // std::cout << std::endl;
    // std::cout << "====[Cat] copy constructor test====" << std::endl;
    // std::cout << "====Cat c====" << std::endl;
    // Cat c;
    // c.setBrain("hello");
    // c.showBrain();
    // std::cout << "====Cat d(c)====" << std::endl;
    // Cat d(c); //복사생성자 생성.
    // d.setBrain("world");
    // d.showBrain();
    // c.showBrain();
    // std::cout << "====d = c====" << std::endl;    
    // c = d;
    // c.showBrain();
    // d.showBrain();

    while(1);

    return 0;
}
