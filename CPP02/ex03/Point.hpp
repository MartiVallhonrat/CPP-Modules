#ifndef POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;
public:
    Point();
    Point(float const x, float const y);
    Point(const Point &other);
    Point   &operator=(const Point &other);
    ~Point();

    Fixed   getX(void) const;
    Fixed   getY(void) const;
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif