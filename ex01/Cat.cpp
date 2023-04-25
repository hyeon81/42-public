#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), brain(new Brain()) {
    std::cout << "[Cat] " << this->type << " is created" << std::endl;
}

Cat:: Cat(const Cat &obj): brain(obj.brain){
    this->type = obj.type;
    std::cout << "[Cat] Copy constructor is called" << std::endl;
}

Cat &Cat:: operator=(const Cat &obj){
    std::cout << "[Cat] Copy assignment operator is called" << std::endl;
    if (&obj == this)
        return (*this);
    this->type = obj.type;
    return (*this);
}

Cat::~Cat(){
    std::cout << "[Cat] is destroyed" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const{
    std::cout << "[Cat] Meow~" << std::endl;
}
