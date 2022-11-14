#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	R2D2("R2D2");
	ScavTrap	PO3("PO3");

	std::cout << std::endl;

	PO3.attack("R2D2");
	PO3.takeDamage(4);
	PO3.beRepaired(3);
	PO3.beRepaired(3);
	PO3.guardGate();

	std::cout << std::endl;

	R2D2.takeDamage(80);
	R2D2.beRepaired(3);
	R2D2.takeDamage(80);
	R2D2.beRepaired(3);

	std::cout << std::endl;
}