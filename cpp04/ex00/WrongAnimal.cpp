#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type(""){
    std::cout << "[WrongAnimal] is created" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type): type(type){
    std::cout << "[WrongAnimal] " << this->type << " is created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj): type(obj.type){
    std::cout << "[WrongAnimal] Copy constructor is called" << std::endl;
}

WrongAnimal &WrongAnimal:: operator=(const WrongAnimal &obj){
    std::cout << "[WrongAnimal] Copy assignment operator is called" << std::endl;
    if (&obj != this)
        this->type = obj.type;
    return (*this);
}

WrongAnimal::~WrongAnimal(){
    std::cout << "[WrongAnimal] " << this->type << " is destroyed" << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << "[WrongAnimal] no sound" << std::endl;
}

const std::string &WrongAnimal::getType() const{
    return (this->type);
}
