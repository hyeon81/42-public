#include "Brain.hpp"

Brain::Brain() {
    std::cout << "[Brain] is created" << std::endl;
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

void Brain::showIdeas()
{
    for (int i = 0; i < 10; i++)
        std::cout << this->ideas[i] << " | ";
    std::cout << std::endl;
}

void Brain::setIdeas(std::string string)
{
    for (int i = 0; i < 10; i++)
        this->ideas[i] = string;
}

