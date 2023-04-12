#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixed_num = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int num)
{
    this->fixed_num = num << this->bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float float_num)
{
    this->fixed_num = roundf(float_num * (1 << this->bits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) //복사 생성자
{
    this->fixed_num = fixed.getRawBits();
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &fixed) // 할당 연산자 오버로딩
{
    if (this != &fixed)
    {
        this->fixed_num = fixed.getRawBits();
    }
    std::cout << "Copy assignment operator called" << std::endl;
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
