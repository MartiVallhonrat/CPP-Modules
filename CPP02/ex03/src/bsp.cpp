#include "../Point.hpp"

static Fixed   myAbs(Fixed x) {
    if (x < 0)
        return x * -1;
    return x;
}

static Fixed   area(const Point a, const Point b, const Point c)
{
    return (myAbs((a.getX() * (b.getY() - c.getY())
            + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()))/2));
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed   A = area(a, b, c);

    Fixed   A1 = area(point, b, c);
    Fixed   A2 = area(a, point, c);
    Fixed   A3 = area(a, b, point);

    return (A == A1 + A2 + A3);
}