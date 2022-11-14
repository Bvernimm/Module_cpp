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
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	Fixed operator++(void);
	Fixed operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
	static Fixed		&min(Fixed &other1, Fixed &other2);
	static const Fixed	&min(const Fixed &other1, const Fixed &other2);
	static Fixed		&max(Fixed &other1, Fixed &other2);
	static const Fixed	&max(const Fixed &other1, const Fixed &other2);
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif