#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
    std::cout << "[WrongCat] " << this->type << " is created" << std::endl;
}

WrongCat:: WrongCat(const WrongCat &obj): WrongAnimal(obj.type) {
    std::cout << "[WrongCat] Copy constructor is called" << std::endl;
}

WrongCat &WrongCat:: operator=(const WrongCat &obj){
    std::cout << "[WrongCat] Copy assignment operator is called" << std::endl;
    if (&obj != this)
        this->type = obj.type;
    return (*this);
}

WrongCat::~WrongCat(){
    std::cout << "[WrongCat] " << this->type << " is destroyed" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "[WrongCat] Meow~" << std::endl;
}
