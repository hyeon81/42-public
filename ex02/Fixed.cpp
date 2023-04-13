#include "Fixed.hpp"

Fixed::Fixed()
{
    this->num = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int num)
{
    this->num = num << this->bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float f_num)
{
    this->num = roundf(f_num * (1 << this->bits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) //복사 생성자
{
    this->num = fixed.getRawBits();
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &fixed) // 할당 연산자 오버로딩
{
    if (this != &fixed)
    {
        this->num = fixed.getRawBits();
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
    return (this->num);
}

void Fixed::setRawBits( int const raw )
{
    this->num = raw;
}

