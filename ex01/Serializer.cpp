#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "[Serializer] is created" << std::endl;
}

Serializer::Serializer(const Serializer &obj)
{
    *this = obj;
    std::cout << "[Serializer] Copy constructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &obj)
{
    std::cout << "[Serializer] Copy assignment operator called" << std::endl;
    if (&obj != this)
        return (*this);
    return (*this);
}

Serializer::~Serializer()
{
    std::cout << "[Serializer] is destroyed" << std::endl;
}
