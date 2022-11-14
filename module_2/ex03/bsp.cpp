#include "Point.hpp"

bool plan ( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	m = (b.gety() - a.gety()) / (b.getx() - a.getx());
	Fixed	p = a.gety() - m * a.getx();
	Fixed	plan1 = m * c.getx() - c.gety() + p;
	Fixed	plan2 = m * point.getx() - point.gety() + p;
	
	if ((plan1 > 0 && plan2 > 0) || (plan1 < 0 && plan2 < 0))
		return (true);
	return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (!plan(a, b, c, point))
		return false;
	if (!plan(b, c, a, point))
		return false;
	if (!plan(c, a, b, point))
		return false;
	return true;
}