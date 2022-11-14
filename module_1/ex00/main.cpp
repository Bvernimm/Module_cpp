#include "Zombie.hpp"

int	main(void)
{
	Zombie	bob("bob");
	bob.announce();

	Zombie	*jo = newZombie("jo");
	jo->announce();
	delete jo;

	randomChump("carl");
	
	return 0;
}