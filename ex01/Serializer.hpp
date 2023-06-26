#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

class Serializer {
    public:
        Serializer();
        Serializer(const Serializer &obj);
        Serializer &operator=(const Serializer &obj);
        ~Serializer();
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif
