#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixed_num = 0;
}

Fixed::Fixed(const int num)
{
    this->fixed_num = num << this->bits;
}

Fixed::Fixed(const float float_num)
{
    this->fixed_num = roundf(float_num * (1 << this->bits));
}

Fixed::Fixed(const Fixed &fixed) 
{
    this->fixed_num = fixed.getRawBits();
}

Fixed &Fixed::operator = (const Fixed &fixed) 
{
    if (this != &fixed)
    {
        this->fixed_num = fixed.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed()
{}

int Fixed::getRawBits( void ) const
{
    return (this->fixed_num);
}

void Fixed::setRawBits( int const raw )
{
    this->fixed_num = raw;
}

int Fixed::toInt( void ) const
{
    return (this->fixed_num >> this->bits);
}

float Fixed::toFloat( void ) const
{
    return ((float)this->fixed_num / (1 << this->bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}

 bool Fixed::operator>(const Fixed &num) const
 {
    return (this->fixed_num > num.fixed_num);
 }

 bool Fixed::operator < (const Fixed &num) const
 {
    return (this->fixed_num < num.fixed_num);
 }

 bool Fixed::operator >= (Fixed &num) const
 {
    return (this->fixed_num >= num.fixed_num);
 }

 bool Fixed::operator <= (Fixed &num) const
 {
    return (this->fixed_num <= num.fixed_num);
 }
 
 bool Fixed::operator == (Fixed &num) const
 {
    return (this->fixed_num == num.fixed_num);
 }

 bool Fixed::operator != (Fixed &num) const
 {
    return (this->fixed_num != num.fixed_num);
 }

Fixed Fixed::operator + (Fixed &num) const
{
    return Fixed(this->toFloat() + num.toFloat());
}


Fixed Fixed::operator - (Fixed &num) const
{
    return Fixed(this->toFloat() - num.toFloat());
}

Fixed Fixed::operator * (const Fixed &num) const
{
    return Fixed(this->toFloat() * num.toFloat());
}

Fixed Fixed::operator / (Fixed &num) const
{
    return Fixed(this->toFloat() / num.toFloat());
}

Fixed &Fixed::operator++(void) //전위 연산자
{
    ++(this->fixed_num);
    return (*this);
}

Fixed &Fixed::operator--(void)
{
    --(this->fixed_num);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);

    ++(*this);
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);

    --(*this);
    return temp;
}

Fixed& Fixed::max(Fixed &fixed_num1, Fixed &fixed_num2)
{
    if (fixed_num1 > fixed_num2)
        return (fixed_num1);
    return (fixed_num2);
}

const Fixed& Fixed::max(const Fixed &fixed_num1, const Fixed &fixed_num2)
{
    if (fixed_num1 > fixed_num2)
        return (fixed_num1);
    return (fixed_num2);
}

Fixed& Fixed::min(Fixed &fixed_num1, Fixed &fixed_num2)
{
    if (fixed_num1 < fixed_num2)
        return (fixed_num1);
    return (fixed_num2);
}

const Fixed& Fixed::min(const Fixed &fixed_num1, const Fixed &fixed_num2)
{
    if (fixed_num1 < fixed_num2)
        return (fixed_num1);
    return (fixed_num2);
}
