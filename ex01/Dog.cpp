#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
    std::cout << "[Dog] " << this->type << " is created" << std::endl;
}

Dog:: Dog(const Dog &obj){
    this->type = obj.type;
    std::cout << "[Dog] Copy constructor is called" << std::endl;
}

Dog &Dog:: operator=(const Dog &obj){
    std::cout << "[Dog] Copy assignment operator is called" << std::endl;
    if (&obj == this)
        return (*this);
    this->type = obj.type;
    return (*this);
}

Dog::~Dog(){
    std::cout << "[Dog] is destroyed" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const{
    std::cout << "[Dog] Bow wow~" << std::endl;
}
