#include "../Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->rawBits = 0;
}

Fixed::Fixed(const int new_rawBits): rawBits(new_rawBits << fracBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float new_rawBits): rawBits(roundf(new_rawBits * (1 << fracBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->rawBits = other.rawBits;
}

Fixed   &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    
    if (this != &other)
        this->rawBits = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return (this->rawBits);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->rawBits = raw;
}

float   Fixed::toFloat(void) const
{
    return (static_cast<float>(this->rawBits)/ (1 << fracBits));
}

int     Fixed::toInt(void) const
{
    return (this->rawBits >> fracBits);
}

std::ostream    &operator<<(std::ostream &o, const Fixed &other)
{
    o << other.toFloat();
    return (o);
}