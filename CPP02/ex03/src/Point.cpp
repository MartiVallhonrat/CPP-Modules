#include "../Point.hpp"

Point::Point(): x(Fixed(0)), y(Fixed(0))
{
}

Point::Point(float const x, float const y): x(Fixed(x)), y(Fixed(y))
{
}

Point::Point(const Point &other): x(other.x), y(other.y)
{
}

Point   &Point::operator=(const Point &other)
{
    if (this == &other)
        return (*this);
    (Fixed)this->x = other.getX();
    (Fixed)this->y = other.getY();
    return (*this);
}

Fixed   Point::getX(void) const
{
    return (this->x);
}

Fixed   Point::getY(void) const
{
    return (this->y);
}

Point::~Point()
{
}
