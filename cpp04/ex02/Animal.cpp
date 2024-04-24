#include "Animal.hpp"

Animal::Animal(): type(""){
    std::cout << "[Animal] is created" << std::endl;
}

Animal::Animal(const std::string type): type(type){
    std::cout << "[Animal] " << this->type << " is created" << std::endl;
}

Animal::Animal(const Animal &obj): type(obj.type){
    std::cout << "[Animal] Copy constructor is called" << std::endl;
}

Animal &Animal:: operator=(const Animal &obj){
    std::cout << "[Animal] Copy assignment operator is called" << std::endl;
    if (&obj != this)
        this->type = obj.type;
    return (*this);
}

Animal::~Animal(){
    std::cout << "[Animal] " << this->type << " is destroyed" << std::endl;
}

const std::string &Animal::getType() const{
    return (this->type);
}