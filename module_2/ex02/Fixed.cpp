#include "Fixed.hpp"

int const Fixed::_bits = 8;

/*---------------------------------------------*/

Fixed::Fixed(void){
	_nb = 0;
	return ;
}

Fixed::Fixed(const Fixed &other){
	_nb = other.getRawBits();
	return ;
}

Fixed::Fixed(int const nb){
	_nb = nb << _bits;
	return ;
}

Fixed::Fixed(float const nb){
	_nb = roundf(nb * (1 << _bits));
	return ;
}

Fixed::~Fixed(void){
	return ;
}

/*---------------------------------------------*/

Fixed &Fixed::operator=(const Fixed &other){
	_nb = other.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &other) const{
	if (_nb > other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &other) const{
	if (_nb < other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &other) const{
	if (_nb >= other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &other) const{
	if (_nb <= other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &other) const{
	if (_nb == other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &other) const{
	if (_nb != other.getRawBits())
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed &other) const{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const{
	return Fixed(toFloat() / other.toFloat());
}

Fixed Fixed::operator++(void){
	_nb = _nb + 1;
	return *this;
}

Fixed Fixed::operator--(void){
	_nb = _nb - 1;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed copy (*this);
	_nb = _nb + 1;
	return copy;
}

Fixed Fixed::operator--(int){
	Fixed copy (*this);
	_nb = _nb - 1;
	return copy;
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

Fixed &Fixed::min(Fixed &other1, Fixed &other2){
	if (other1 <= other2)
		return other1;
	return other2;
}

const Fixed &Fixed::min(const Fixed &other1, const Fixed &other2){
	if (other1 <= other2)
		return other1;
	return other2;
}

Fixed &Fixed::max(Fixed &other1, Fixed &other2){
	if (other1 >= other2)
		return other1;
	return other2;
}

const Fixed &Fixed::max(const Fixed &other1, const Fixed &other2){
	if (other1 >= other2)
		return other1;
	return other2;
}

/*---------------------------------------------*/

std::ostream &operator<<(std::ostream &os, Fixed const &fixed) {
	os << fixed.toFloat();
	return (os);
}