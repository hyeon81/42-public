#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    this->brain = new Brain();
    std::cout << "[Dog] " << this->type << " is created" << std::endl;
}

Dog:: Dog(const Dog &obj){
    std::cout << "[Dog] Copy constructor is called" << std::endl;
    this->type = obj.type;

    this->brain = new Brain();
    *(this->brain) = *(obj.brain);
}

Dog &Dog:: operator=(const Dog &obj){
    std::cout << "[Dog] Copy assignment operator is called" << std::endl;
    if (&obj != this)
    {
        delete this->brain;
        this->type = obj.type;
        this->brain = new Brain();
        *(this->brain) = *(obj.brain); // Copy assignment operator is called
    }
    return (*this);
}

Dog::~Dog(){
    std::cout << "[Dog] is destroyed" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const{
    std::cout << "[Dog] Bow wow~" << std::endl;
}

void Dog::showBrain(){
    this->brain->showIdeas();
}

void Dog::setBrain(std::string string){
    this->brain->setIdeas(string);
}
