#include "../Fixed.hpp"
#include "../Point.hpp"

int main(void)
{
    Point   a(1.5f, 3);
    Point   b(4.2f, 1.8f);
    Point   c(3.6f, 5.1f);

    Point   inPoint(3.48f, 3.03f);
    Point   outPoint(42, 42.42f);

    if (bsp(a, b, c, inPoint))
        std::cout << "Point Inside!" << std::endl;
    else
        std::cout << "Point Outside!" << std::endl;

        
    if (bsp(a, b, c, outPoint))
        std::cout << "Point Inside!" << std::endl;
    else
        std::cout << "Point Outside!" << std::endl;

    return (0);
}