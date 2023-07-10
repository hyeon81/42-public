#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T> //다 붙여줘야함
void swap(T &a, T &b){ //값 자체가 변경되어야 하므로 레퍼런스로...
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T &a, T &b){
    if (a >= b)
        return b;
    return a;
}

template <typename T>
T max(T &a, T &b){
    if (a <= b)
        return b;
    return a;
}

#endif