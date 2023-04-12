#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixed_num = 0;
}

Fixed::Fixed(const Fixed &fixed) //복사 생성자
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_num = fixed.getRawBits();
}

Fixed &Fixed::operator = (const Fixed &fixed) // 할당 연산자 오버로딩
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
    {
        this->fixed_num = fixed.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_num);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed_num = raw;
}
