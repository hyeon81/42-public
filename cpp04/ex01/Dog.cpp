#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
    std::cout << "[Dog] " << this->type << " is created" << std::endl;
}

Dog:: Dog(const Dog &obj): Animal(obj.type), brain(new Brain()){
    std::cout << "[Dog] Copy constructor is called" << std::endl;
    *(this->brain) = *(obj.brain);
}

Dog &Dog:: operator=(const Dog &obj){
    std::cout << "[Dog] Copy assignment operator is called" << std::endl;
    if (&obj != this)
    {
        delete this->brain;
        this->type = obj.type;
        this->brain = new Brain();
        *(this->brain) = *(obj.brain);
    }
    return (*this);
}

Dog::~Dog(){
    delete this->brain;
    std::cout << "[Dog] " << this->type << " is destroyed" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "[Dog] bark!!!" << std::endl;
}

void Dog::showBrain(){
    this->brain->showIdeas();
}

void Dog::setBrain(std::string string){
    this->brain->setIdeas(string);
}
