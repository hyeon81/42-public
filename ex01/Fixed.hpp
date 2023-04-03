#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed {
    private:
        int num;
        const static int bits = 8;
    
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &fixed);
        Fixed &operator = (const Fixed &fixed);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif
