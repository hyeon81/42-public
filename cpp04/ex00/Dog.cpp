#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "[Dog] " << this->type << " is created" << std::endl;
}

Dog:: Dog(const Dog &obj): Animal(obj.type) {
    std::cout << "[Dog] Copy constructor is called" << std::endl;
}

Dog &Dog:: operator=(const Dog &obj){
    std::cout << "[Dog] Copy assignment operator is called" << std::endl;
    if (&obj != this)
        this->type = obj.type;
    return (*this);
}

Dog::~Dog(){
    std::cout << "[Dog] " << this->type << " is destroyed" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "[Dog] bark!!!~" << std::endl;
}
