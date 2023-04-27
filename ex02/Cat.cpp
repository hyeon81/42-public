#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), brain(new Brain()) {
    std::cout << "[Cat] " << this->type << " is created" << std::endl;
}

Cat:: Cat(const Cat &obj): Animal(obj.type), brain(new Brain()) {
    std::cout << "[Cat] Copy constructor is called" << std::endl;
    *(this->brain) = *(obj.brain);
}

Cat &Cat:: operator=(const Cat &obj){
    std::cout << "[Cat] Copy assignment operator is called" << std::endl;
    if (&obj != this)
    {
        delete this->brain;
        this->type = obj.type;
        this->brain = new Brain();
        *(this->brain) = *(obj.brain);
    }
    return (*this);
}

Cat::~Cat(){
    delete this->brain;
    std::cout << "[Cat] " << this->type << " is destroyed" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "[Cat] Meow~" << std::endl;
}

void Cat::showBrain(){
    this->brain->showIdeas();
}

void Cat::setBrain(std::string string){
    this->brain->setIdeas(string);
}
