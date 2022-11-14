#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	FragTrap	R2D2("R2D2");
	ScavTrap	PO3("PO3");
	DiamondTrap	Spamton("Spamton_NEO");

	std::cout << std::endl;

	PO3.attack("R2D2");
	R2D2.attack("PO3");
	PO3.guardGate();
	R2D2.highFivesGuys();

	std::cout << std::endl;

	Spamton.attack("PO3");
	Spamton.beRepaired(5);
	Spamton.guardGate();
	Spamton.highFivesGuys();
	Spamton.whoAmI();

	std::cout << std::endl;
}