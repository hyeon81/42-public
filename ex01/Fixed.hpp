#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed {
    private:
        int num;
        float f_num;
        const static int bits = 8;
    
    public:
        Fixed();
        Fixed(int num);
        Fixed(float f_num);
        ~Fixed();
        Fixed(const Fixed &fixed);
        Fixed &operator = (const Fixed &fixed);
        float toFloat( void ) const;
        int toInt( void ) const;
        //연산자 오버로딩 필요
};

#endif
