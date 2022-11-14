#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	R2D2("R2D2");
	ClapTrap	PO3("PO3");

	std::cout << std::endl;

	PO3.attack("R2D2");
	PO3.takeDamage(4);
	PO3.beRepaired(3);
	PO3.beRepaired(3);

	std::cout << std::endl;

	R2D2.takeDamage(100);
	R2D2.beRepaired(3);

	std::cout << std::endl;
}