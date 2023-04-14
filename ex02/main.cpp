#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed z(2);

    std::cout << "=====main test=====" << std::endl;
    std::cout << "z : " << z.getRawBits() << std::endl;
    std::cout << "a : " << a << std::endl;
    std::cout << "++a : " << ++a << std::endl;
    std::cout << "a : " << a << std::endl;
    std::cout << "a++ : " << a++ << std::endl;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "max : " << Fixed::max( a, b ) << std::endl;

    std::cout << "=====self test=====" << std::endl;

    Fixed c(1);
    Fixed d(2);

    std::cout << "c > d : " << (c > d) << std::endl;
    std::cout << "c < d : " << (c < d) << std::endl;
    std::cout << "c >= d : " << (c >= d) << std::endl;
    std::cout << "c <= d : " << (c <= d) << std::endl;
    std::cout << "c == d : " << (c == d) << std::endl;
    std::cout << "c != d : " << (c != d) << std::endl;
    std::cout << "c : " << c << std::endl;
    std::cout << "d : " << d << std::endl;
    Fixed res = c + d;
    std::cout << "c + d : " << res << std::endl;
    res = c - d;
    std::cout << "c - d : " << res << std::endl;
    res = c * d;
    std::cout << "c * d : " << res << std::endl;
    res = c / d;
    std::cout << "c / d : " << res << std::endl;
    std::cout << "d : " << d << std::endl;
    std::cout << "--d : " << --d << std::endl;
    std::cout << "d : " << d << std::endl;
    std::cout << "d--: " << d-- << std::endl;
    std::cout << "d : " << d << std::endl;
    std::cout << "min : " << Fixed::max(c,d) << std::endl;

    return (0);
}
