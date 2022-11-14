#include "Fixed.hpp"

int const Fixed::_bits = 8;

/*---------------------------------------------*/

Fixed::Fixed(void){
	std::cout << "Default constructor called\n";
	_nb = 0;
	return ;
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called\n";
	_nb = other.getRawBits();
	return ;
}

Fixed::Fixed(int const nb){
	std::cout << "Int constructor called" << std::endl;
	_nb = nb << _bits;
	return ;
}

Fixed::Fixed(float const nb){
	std::cout << "Float constructor called" << std::endl;
	_nb = roundf(nb * (1 << _bits));
	return ;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called\n";
	return ;
}

/*---------------------------------------------*/

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called\n";
	_nb = other.getRawBits();
	return *this;
}

/*---------------------------------------------*/

int		Fixed::getRawBits(void) const{
	return (_nb);
}

void	Fixed::setRawBits(int const raw){
	_nb = raw;
}

float	Fixed::toFloat(void) const{
	return ( (float) _nb / (1 << _bits));
}

int		Fixed::toInt(void) const{
	return (_nb >> _bits);
}

/*---------------------------------------------*/

std::ostream &operator<<(std::ostream &os, Fixed const &fixed) {
	os << fixed.toFloat();
	return (os);
}