#include "Fixed.hpp"

Fixed::Fixed()
{
    this->num = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int num)
{
    this->num = num >> this->bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float f_num)
{
    this->num = roundf(f_num * (1 << this->bits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) //복사 생성자
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &fixed) // 할당 연산자 오버로딩
{
    if (this != &fixed)
    {

    }
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt( void ) const
{
    return (this->num >> this->bits);
}

float Fixed::toFloat( void ) const
{
    return ((float)this->num / (1 << this->bits));
}

//연산자 오버라이딩
std::ostream& operaotr << (std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}
