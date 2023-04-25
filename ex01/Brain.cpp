#include "Brain.hpp"

Brain::Brain() {
    std::cout << "[Brain] is created" << std::endl;
    //ideas 초기화?
}

Brain:: Brain(const Brain &obj){
    std::cout << "[Brain] Copy constructor is called" << std::endl;
    for(int i = 0; i < 100; i++)
        this->ideas[i] = obj.ideas[i];
}

Brain &Brain:: operator=(const Brain &obj){
    std::cout << "[Brain] Copy assignment operator is called" << std::endl;
    if (&obj == this)
        return (*this);
    for(int i = 0; i < 100; i++)
        this->ideas[i] = obj.ideas[i];
    return (*this);
}

Brain::~Brain(){
    std::cout << "[Brain] is destroyed" << std::endl;
}

