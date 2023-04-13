#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixed_num = 0;
}

Fixed::Fixed(int num)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_num = num << this->bits;
}

Fixed::Fixed(float float_num)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_num = roundf(float_num * (1 << this->bits));
}

Fixed::Fixed(const Fixed &fixed) //복사 생성자
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_num = fixed.getRawBits();
}

Fixed &Fixed::operator = (const Fixed &fixed) // 할당 연산자 오버로딩
{
    std::cout << "Copy assignment operator called" << std::endl;
     if (this == &fixed)
        return (*this); 
    this->fixed_num = fixed.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

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

//연산자 오버라이딩
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}
