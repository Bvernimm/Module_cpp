#include "Zombie.hpp"

int	main(void)
{
	Zombie	*dave = zombieHorde(8, "dave");
	
	for (int i = 0; i < 8; i++)
		dave[i].announce();
	delete[] dave;

	return 0;
}