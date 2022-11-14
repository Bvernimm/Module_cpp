#include "Point.hpp"

int main( void )
{
	Point	a (1, 2);
	Point	b (3.5, 4);
	Point	c (3, 1);
	Point	point (2, 2);
	
	if (bsp(a, b, c, point))
		std::cout << "He's in !\n";
	else
		std::cout << "Nop !\n";
	return 0;
}