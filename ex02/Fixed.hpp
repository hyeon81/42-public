#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed {
    private:
        int fixed_num;
        const static int bits = 8;
    
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float float_num);
        ~Fixed();
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        //비교연산자
        bool operator >(const Fixed &num) const; 
        bool operator < (const Fixed &num) const;
        bool operator >= (Fixed &num) const;
        bool operator <= (Fixed &num) const;
        bool operator == (Fixed &num) const;
        bool operator != (Fixed &num) const;
    
        //산술연산자
        Fixed operator+(Fixed &num) const;
        Fixed operator-(Fixed &num) const;
        Fixed operator*(const Fixed &num) const;
        Fixed operator/(Fixed &num) const;

        //증감연산자
        Fixed &operator++(void);
        Fixed &operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);

        static Fixed &max(Fixed &fixed_num1, Fixed &fixed_num2);
        static const Fixed &max(const Fixed &fixed_num1, const Fixed &fixed_num2);
        static Fixed &min(Fixed &fixed_num1, Fixed &fixed_num2);
        static const Fixed &min(const Fixed &fixed_num1, const Fixed &fixed_num2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
