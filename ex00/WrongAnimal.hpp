#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const std::string type);
        WrongAnimal(const WrongAnimal &obj);
        WrongAnimal &operator=(const WrongAnimal &obj);
        ~WrongAnimal();
        void makeSound() const;
        const std::string &getType() const;
};

#endif