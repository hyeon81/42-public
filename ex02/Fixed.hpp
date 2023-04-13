#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed {
    private:
        int num;
        const static int bits = 8;
    
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &fixed);
        Fixed &operator = (const Fixed &fixed);

        Fixed(int num);
        Fixed(float f_num);

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        //비교연산자
        bool operator > (Fixed &num) const; //리턴값이 bool이기 때문
        bool operator < (Fixed &num) const;
        bool operator >= (Fixed &num) const;
        bool operator <= (Fixed &num) const;
        bool operator == (Fixed &num) const;
        bool operator != (Fixed &num) const;
    
        //계산연산자
        Fixed operator + (Fixed &num) const;
        Fixed operator - (Fixed &num) const;
        Fixed operator * (Fixed &num) const;
        Fixed operator / (Fixed &num) const;

        Fixed &operator++(void);
        Fixed &operator--(void);
        const Fixed operator++(int);
        const Fixed operator--(int);

        int &max(int &a, int &b);
};

#endif
