#include "../Fixed.hpp"

Fixed::Fixed()
{
    this->rawBits = 0;
}

Fixed::Fixed(const int new_rawBits): rawBits(new_rawBits << fracBits)
{
}

Fixed::Fixed(const float new_rawBits): rawBits(roundf(new_rawBits * (1 << fracBits)))
{
}

Fixed::Fixed(const Fixed &other)
{
    this->rawBits = other.rawBits;
}

Fixed   &Fixed::operator=(const Fixed &other)
{ 
    if (this != &other)
        this->rawBits = other.getRawBits();
    return (*this);
}

std::ostream    &operator<<(std::ostream &o, const Fixed &other)
{
    o << other.toFloat();
    return (o);
}

bool    Fixed::operator>(const Fixed &other) const
{
    return (this->getRawBits() > other.getRawBits());
}

bool    Fixed::operator<(const Fixed &other) const
{
    return (this->getRawBits() < other.getRawBits());
}

bool    Fixed::operator>=(const Fixed &other) const
{
    return (this->getRawBits() >= other.getRawBits());
}

bool    Fixed::operator<=(const Fixed &other) const
{
    return (this->getRawBits() <= other.getRawBits());
}

bool    Fixed::operator==(const Fixed &other) const
{
    return (this->getRawBits() == other.getRawBits());
}

bool    Fixed::operator!=(const Fixed &other) const
{
    return (this->getRawBits() != other.getRawBits());
}

Fixed   Fixed::operator+(const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed   Fixed::operator-(const Fixed &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed   Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed   Fixed::operator/(const Fixed &other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed   &Fixed::operator++(void)
{
    ++(this->rawBits);
    return (*this);
}

Fixed   &Fixed::operator--(void)
{
    ++(this->rawBits);
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp(*this);
    tmp.setRawBits(this->rawBits++);
    return (tmp);
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp(*this);
    tmp.setRawBits(this->rawBits--);
    return (tmp);
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    return (a.getRawBits() > b.getRawBits() ? a : b);
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() > b.getRawBits() ? a : b);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
    return (this->rawBits);
}

void    Fixed::setRawBits(int const raw)
{
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