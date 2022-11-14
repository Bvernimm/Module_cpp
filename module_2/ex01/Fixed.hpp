#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_nb;
	static const int	_bits;
public:
	Fixed(void);
	Fixed(int const nb);
	Fixed(float const nb);
	Fixed(const Fixed &other);
	~Fixed(void);

	Fixed &operator=(const Fixed &other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif