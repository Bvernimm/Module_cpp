#include "Point.hpp"

Point::Point(void):
	_x (Fixed(0)),
	_y (Fixed(0))
{}

Point::Point(const float x, const float y):
	_x (x),
	_y (y)
{}

Point::Point(const Point &other):
	_x (other.getx()),
	_y (other.gety())
{}

Point::~Point(void){
	return ;
}

/*---------------------------------------------*/

Point &Point::operator=(const Point &other){
	(void) other;
	return *this;
}

/*---------------------------------------------*/

const Fixed	&Point::getx(void) const{
	return (_x);
}

const Fixed	&Point::gety(void) const{
	return (_y);
}