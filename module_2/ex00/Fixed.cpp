#include "Fixed.hpp"

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

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called\n";
	_nb = other.getRawBits();
	return *this;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called\n";
	return ;
}

int		Fixed::getRawBits(void)	const{
	std::cout << "getRawBits member function called\n";
	return (_nb);
}

void	Fixed::setRawBits(int const raw){
	_nb = raw;
}