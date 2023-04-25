#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const std::string type);
        Animal(const Animal &obj);
        Animal &operator=(const Animal &obj);
        virtual ~Animal();
        void makeSound() const;
        const std::string &getType() const;
};

#endif