#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed {
    public:
        Fixed();
        ~Fixed();
        bool operator > (Fixed &num) const;
        bool operator < (Fixed &num) const;
        bool operator >= (Fixed &num) const;
        bool operator <= (Fixed &num) const;
        bool operator == (Fixed &num) const;
        bool operator != (Fixed &num) const;


};

#endif
