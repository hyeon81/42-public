#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *addr, unsigned int len, void (*fn)(const T&))
{
    if (!fn)
        return ;
    for (unsigned int i = 0; i < len; i++)
    {
        fn(addr[i]);
    }
}

template <typename T>
void print(T &element)
{
    std::cout << element << std::endl;
}

#endif