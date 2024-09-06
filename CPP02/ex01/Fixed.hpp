#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
    int rawBits;
    static const int fracBits = 8;
public:
    Fixed();
    Fixed(const int rawBits);
    Fixed(const float rawBits);
    Fixed(const Fixed &other);
    Fixed   &operator=(const Fixed &other);
    ~Fixed();

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream    &operator<<(std::ostream &o, const Fixed &other);

#endif