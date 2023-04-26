#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), brain(new Brain()) {
    std::cout << "[Cat] " << this->type << " is created" << std::endl;
}

Cat:: Cat(const Cat &obj) {
    std::cout << "[Cat] Copy constructor is called" << std::endl;
    this->type = obj.type;

    this->brain = new Brain();
    *(this->brain) = *(obj.brain);
}

Cat &Cat:: operator=(const Cat &obj){
    std::cout << "[Cat] Copy assignment operator is called" << std::endl;
    if (&obj != this)
    {
        delete this->brain;
        this->type = obj.type;
        this->brain = new Brain();
        *(this->brain) = *(obj.brain); // Copy assignment operator is called
    }
    return (*this);
}

Cat::~Cat(){
    std::cout << "[Cat] is destroyed" << std::endl;
    delete this->brain;
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
