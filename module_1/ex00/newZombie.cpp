#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie	*newZombie = NULL;

	newZombie = new Zombie(name);
	return (newZombie);
}